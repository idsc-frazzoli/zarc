/*
 * encoder_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "encoder_data_logger.h"

enc_log::EncDataLogger::EncDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize,
        std::string csvHeader, std::string loggerType) :
        BASE(buffSize, outFilename, csvHeader, loggerType) {
    m_sub = n.subscribe(rosTopicName, rosQueueSize, &EncDataLogger::msgCallback, this);
}

void enc_log::EncDataLogger::msgCallback(msgPtr_t msg) {

    static double timeOffset = -1;

    if (timeOffset < 0)
        timeOffset = msg->time;

    std::vector<double> data;

    data.push_back(msg->time - timeOffset);
    data.push_back(msg->FL);
    data.push_back(msg->FR);
    data.push_back(msg->BL);
    data.push_back(msg->BR);

    addToBuff(data);
}

