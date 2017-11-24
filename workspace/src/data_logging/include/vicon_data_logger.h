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

class ViconDataLogger: public DataLogger<geometry_msgs::TransformStamped::ConstPtr> {

public:
    ViconDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize);

    virtual ~ViconDataLogger() {
    }

    void msgCallback(geometry_msgs::TransformStamped::ConstPtr msg) override;

    //TODO remove this
    void dumpToFile1();


private:


};

#endif /* VICON_DATA_LOGGER_H_ */
