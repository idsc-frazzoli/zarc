/*
 * ViconDataLogger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef VICON_DATA_LOGGER_H_
#define VICON_DATA_LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <boost/circular_buffer.hpp>
#include <Eigen/Dense>
#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include "logger.h"

struct DataVicon {

    double time;
    Eigen::Matrix<double, 3, 1> pos;
    Eigen::Matrix<double, 3, 1> rot;
    Eigen::Quaternion<double> q;
};

using msgPtr_t = geometry_msgs::TransformStamped::ConstPtr;

class ViconDataLogger: public DataLogger<msgPtr_t> {

typedef DataLogger<msgPtr_t> BASE;


public:
    ViconDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize);

    virtual ~ViconDataLogger() {
    }

    void msgCallback(msgPtr_t msg) override;


private:


};

#endif /* VICON_DATA_LOGGER_H_ */
