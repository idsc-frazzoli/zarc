/*
 * encoder_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "encoder_data_logger.h"
#include <ctime>

    EncDataLogger::EncDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize ) :
    m_filename(filename) {
        m_buffer.set_capacity(buffSize);
        m_sub = n.subscribe(topic, queueSize, &EncDataLogger::msgCallback, this);

    }

    void EncDataLogger::msgCallback(barc::Velocity::ConstPtr msg) {

        static double timeOffset = -1;

        if (timeOffset < 0)
            timeOffset = msg->time;

        VelData velData;

        velData.time = msg->time - timeOffset;
        velData.velFL = msg->FL;
        velData.velFR = msg->FR;
        velData.velBL = msg->BL;
        velData.velBR = msg->BR;

        m_buffer.push_back(velData);
    }


    void EncDataLogger::dumpToFile() {


        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
        std::string time(buffer);

        m_filename = m_filename + "_" + time + ".csv";


        // create and open the .csv file
        std::ofstream file;

        file.open(m_filename);

        // write the file headers
        file << "time, velFL, velFR, velBL, velBR" << std::endl;

        for (boost::circular_buffer<VelData>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
            file << it->time << ", " << it->velFL << ", " << it->velFR << ", " << it->velBL << ", " << it->velBR << std::endl;

        // close the output file
        file.close();
    }


