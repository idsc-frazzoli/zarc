/*
 * vicon_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "vicon_data_logger.h"

vicon_log::ViconDataLogger::ViconDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize,
        std::string csvHeader, std::string loggerType) :
        BASE(buffSize, outFilename, csvHeader, loggerType), m_timeOffset(-1.0) {
    m_sub = n.subscribe(rosTopicName, rosQueueSize, &ViconDataLogger::msgCallback, this);
}

void vicon_log::ViconDataLogger::msgCallback(msgPtr_t msg) {

    if (m_timeOffset < 0)
        m_timeOffset = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9;

    std::vector<double> data;

    //the order has to match to the one in the header
    data.push_back(msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9 - m_timeOffset);
    data.push_back(msg->transform.translation.x);
    data.push_back(msg->transform.translation.y);
    data.push_back(msg->transform.translation.z);
    data.push_back(msg->transform.rotation.w);
    data.push_back(msg->transform.rotation.x);
    data.push_back(msg->transform.rotation.y);
    data.push_back(msg->transform.rotation.z);

    Eigen::Quaternion<double> q(msg->transform.rotation.w, msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z);
    Eigen::Matrix<double, 3, 1> rot = q.toRotationMatrix().eulerAngles(0, 1, 2);
    data.push_back(rot(0));
    data.push_back(rot(1));
    data.push_back(rot(2));

    addToBuff(data);

}

