/*
 * logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <string>

template<typename MSGTYPEPTR>
class DataLogger {

public:

    DataLogger();

    virtual ~DataLogger() {};

    virtual void msgCallback(MSGTYPEPTR msg) = 0;

    std::string getCurrTime();

    void dumpToFile ();



private:
    boost::circular_buffer<std::vector<double> > m_buffer;
    std::string m_filename;
    std::string m_header;
    ros::Subscriber m_sub;


};

#endif /* LOGGER_H_ */
