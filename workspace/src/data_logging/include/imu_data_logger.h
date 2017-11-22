/*
 * imu_data_logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef IMU_DATA_LOGGER_H_
#define IMU_DATA_LOGGER_H_


#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/circular_buffer.hpp>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <Eigen/Dense>
#include "logger.h"


struct ImuData {

    double time;
    Eigen::Matrix<double, 3, 1> linAcc;
    Eigen::Matrix<double, 3, 1> angVel;
    Eigen::Quaternion<double> q;

};

class ImuDataLogger : public DataLogger {

public:
    ImuDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize );

    virtual ~ImuDataLogger() {}

    void msgCallback(sensor_msgs::Imu::ConstPtr msg);

    void dumpToFile() override ;

private:
    boost::circular_buffer<ImuData> m_buffer;
    std::string m_filename;
    std::ofstream m_file;
    ros::Subscriber m_sub;

};


#endif /* IMU_DATA_LOGGER_H_ */
