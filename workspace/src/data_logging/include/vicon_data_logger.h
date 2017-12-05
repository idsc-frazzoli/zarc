/*
 * ViconDataLogger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef VICON_DATA_LOGGER_H_
#define VICON_DATA_LOGGER_H_

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include "logger.h"

namespace vicon_log {

using msgPtr_t = geometry_msgs::TransformStamped::ConstPtr;

class ViconDataLogger: public DataLogger<msgPtr_t> {

public:
    ViconDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize, std::string csvHeader, std::string loggerType);

    void msgCallback(msgPtr_t msg) override;

private:
    ros::Subscriber m_sub;
    typedef DataLogger<msgPtr_t> BASE;
    double m_timeOffset;

};

} /*vicon*/

#endif /* VICON_DATA_LOGGER_H_ */
