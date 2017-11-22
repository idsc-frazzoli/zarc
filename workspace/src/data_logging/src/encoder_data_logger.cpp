/*
 * encoder_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "encoder_data_logger.h"

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
        velData.vel = msg->velocity;

        m_buffer.push_back(velData);
    }


    void EncDataLogger::dumpToFile() {

        // create and open the .csv file
        m_file.open(m_filename);

        // write the file headers
        m_file << "time, vel_enc" << std::endl;

        for (boost::circular_buffer<VelData>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
            m_file << it->time << ", " << it->vel << std::endl;

        // close the output file
        m_file.close();
    }


