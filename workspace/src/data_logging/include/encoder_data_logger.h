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

class EncDataLogger: public DataLogger {

public:
    EncDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize);

    virtual ~EncDataLogger() {
    }

    void msgCallback(barc::Velocity::ConstPtr msg);

    void dumpToFile() override;

private:
    boost::circular_buffer<VelData> m_buffer;
    std::string m_filename;
    std::ofstream m_file;
    ros::Subscriber m_sub;

};

#endif /* SRC_DATA_LOGGING_INCLUDE_ENCODER_DATA_LOGGER_H_ */
