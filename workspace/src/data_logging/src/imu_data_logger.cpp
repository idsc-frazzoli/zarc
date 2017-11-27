/*
 * imu_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "imu_data_logger.h"

imu_log::ImuDataLogger::ImuDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize,
        std::string csvHeader, std::string loggerType) :
        BASE(buffSize, outFilename, csvHeader, loggerType) {
    m_sub = n.subscribe(rosTopicName, rosQueueSize, &ImuDataLogger::msgCallback, this);
}

void imu_log::ImuDataLogger::msgCallback(msgPtr_t msg) {

    static double timeOffset = -1;

    if (timeOffset < 0)
        timeOffset = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9;

    std::vector<double> data;

    //time
    data.push_back(msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9 - timeOffset);

    //ang vel
    data.push_back(msg->angular_velocity.x);
    data.push_back(msg->angular_velocity.y);
    data.push_back(msg->angular_velocity.z);

    // lin acc
    data.push_back(msg->linear_acceleration.x);
    data.push_back(msg->linear_acceleration.y);
    data.push_back(msg->linear_acceleration.z);

    // quaternion
    data.push_back(msg->orientation.x);
    data.push_back(msg->orientation.y);
    data.push_back(msg->orientation.z);
    data.push_back(msg->orientation.w);

    addToBuff(data);
}

