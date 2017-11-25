/*
 * imu_data_logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef IMU_DATA_LOGGER_H_
#define IMU_DATA_LOGGER_H_

#include <iostream>
#include <string>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include "logger.h"

namespace imu_log {

using msgPtr_t = sensor_msgs::Imu::ConstPtr;

class ImuDataLogger: public DataLogger<msgPtr_t> {

public:

    ImuDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize, std::string header);

    virtual ~ImuDataLogger() {
    }

    void msgCallback(msgPtr_t msg) override;

private:

    ros::Subscriber m_sub;
    typedef DataLogger<msgPtr_t> BASE;

};

} /*imu_log*/

#endif /* IMU_DATA_LOGGER_H_ */
