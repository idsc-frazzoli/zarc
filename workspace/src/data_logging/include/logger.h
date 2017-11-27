/*
 * logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <boost/circular_buffer.hpp>
#include <boost/filesystem.hpp>

class IDataLogger {
public:
    IDataLogger() {
    }
    virtual ~IDataLogger() {
    }
    virtual void dumpToFile() = 0;
};

template<typename MSGTYPEPTR>
class DataLogger: public IDataLogger {

public:

    typedef boost::circular_buffer<std::vector<double> > buffer_t;

    DataLogger(int buffSize, std::string outFilename, std::string csvHeader, std::string loggerType) :
            m_outFilename(outFilename), m_csvHeader(csvHeader), m_dumpedToFile(false), m_loggerType(loggerType) {
        m_buffer.set_capacity(buffSize);
    }

    virtual ~DataLogger() {
        dumpToFile(); //caller should dump to file or automatically?
    }

    virtual void msgCallback(MSGTYPEPTR msg) = 0;

    void dumpToFile() override {

        if (m_dumpedToFile)
            return;

        std::string fileName = m_outFilename + "_" + getCurrTime() + ".csv";
        std::ofstream file;
        file.open(fileName);

        // write the file headers
        file << m_csvHeader << std::endl;

        for (buffer_t::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++) {
            for (int i = 0; i < it->size(); i++)
                file << it->at(i) << ", ";
            file << std::endl;
        }

        // close the output file
        file.close();

        m_dumpedToFile = true;

        //current working directory
        boost::filesystem::path full_path(boost::filesystem::current_path());
        std::cout << " \n" << m_loggerType << " terminated. Saving measurements into: " << full_path << std::endl;
    }
protected:

    std::string getCurrTime() {
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y_%I:%M:%S", timeinfo);
        return std::string(buffer);

    }

    void addToBuff(const std::vector<double>& vec) {
        m_buffer.push_back(vec);
    }

private:
    buffer_t m_buffer;
    std::string m_outFilename;
    std::string m_csvHeader;
    bool m_dumpedToFile;
    std::string m_loggerType;

};

#endif /* LOGGER_H_ */
