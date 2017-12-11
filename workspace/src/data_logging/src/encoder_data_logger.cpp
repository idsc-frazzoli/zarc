/*
 * encoder_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "encoder_data_logger.h"

enc_log::EncDataLogger::EncDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize,
        std::string csvHeader, std::string loggerType) :
        BASE(buffSize, outFilename, csvHeader, loggerType), m_timeOffset(-1.0) {
    m_sub = n.subscribe(rosTopicName, rosQueueSize, &EncDataLogger::msgCallback, this); //TODO m_sub in the base class
    //TODO allow to start and stop the logging from the outside world
}

void enc_log::EncDataLogger::msgCallback(msgPtr_t msg) {

//    if (m_timeOffset < 0)
//        m_timeOffset = msg->time;

    std::vector<double> data;

    //data.push_back(msg->time - m_timeOffset);
    data.push_back(msg->v_FL);
    data.push_back(msg->v_FR);
    data.push_back(msg->v_BL);
    data.push_back(msg->v_BR);

    addToBuff(data);
}

