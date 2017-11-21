/*
 * encoder_data_logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef ENCODER_DATA_LOGGER_H_
#define ENCODER_DATA_LOGGER_H_


#include <iostream>
#include <fstream>
#include <string>
#include <boost/circular_buffer.hpp>
#include <Eigen/Dense>
#include <ros/ros.h>
#include "barc/Velocity.h"
#include "logger.h"

struct VelData {
    double time;
    double vel;
};

class EncDataLogger : public DataLogger {

public:
    EncDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize ) :
            m_filename("Vel" + filename) {
        m_buffer.set_capacity(buffSize);
        m_sub = n.subscribe("forward_vel", queueSize, &EncDataLogger::msgCallback, this)

    }

    virtual ~EncDataLogger() {}

    void msgCallback(barc::Velocity::ConstPtr msg) {

        static double timeOffset = -1;

        if (timeOffset < 0)
            timeOffset = msg->time;

        VelData velData;

        velData.time = msg->time - timeOffset;
        velData.vel = msg->velocity;

        m_buffer.push_back(velData);
    }


    void dumpToFile() {

        // create and open the .csv file
        m_file.open(m_filename);

        // write the file headers
        m_file << "time, vel_enc" << std::endl;

        for (boost::circular_buffer<VelData>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
            m_file << it->time << ", " << it->vel << std::endl;

        // close the output file
        m_file.close();
    }

private:
    boost::circular_buffer<VelData> m_buffer;
    std::string m_filename;
    std::ofstream m_file;
    ros::Subscriber m_sub;

};


#endif /* SRC_DATA_LOGGING_INCLUDE_ENCODER_DATA_LOGGER_H_ */
