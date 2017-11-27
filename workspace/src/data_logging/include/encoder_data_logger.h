/*
 * encoder_data_logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef ENCODER_DATA_LOGGER_H_
#define ENCODER_DATA_LOGGER_H_

#include <iostream>
#include <string>
#include <ros/ros.h>
#include "barc/Velocity.h"
#include "logger.h"

namespace enc_log {

using msgPtr_t = barc::Velocity::ConstPtr;

class EncDataLogger: public DataLogger<msgPtr_t> {

public:

    EncDataLogger(int buffSize, std::string outFilename, std::string rosTopicName, ros::NodeHandle& n, int rosQueueSize, std::string csvHeader,
            std::string loggerType);

//    virtual ~EncDataLogger() {
//    }

    void msgCallback(msgPtr_t msg);

private:

    ros::Subscriber m_sub;
    typedef DataLogger<msgPtr_t> BASE;
    double m_timeOffset;

};

} /*enc_log*/

#endif /* ENCODER_DATA_LOGGER_H_ */
