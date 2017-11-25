/*
 * logger_node.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */



// inlcude iostream and string libraries
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ros/ros.h>
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include "encoder_data_logger.h"
#include "imu_data_logger.h"
#include "vicon_data_logger.h"

volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}

class LoggerFactory {

public:

    enum LoggerType {
        VICON,
        IMU,
        ENCODER
    };

LoggerFactory(){}
~LoggerFactory(){}

void loadSettings(std::string filename){
    YAML::Node config = YAML::LoadFile(filename);

    if (config.IsNull())
        throw  std::runtime_error("YAML couldn't find: " + filename);//File Not Found?

    for(YAML::const_iterator it=config.begin(); it != config.end(); it++) {
       std::string key = it->first.as<std::string>();       // <- key
       std::cout << key << std::endl;
    }

}




};

int main(int argc, char** argv) {


    if (argc < 2)
        throw std::runtime_error("No config file provided");

    std::string configFile(argv[1]);

    std::cout << configFile << std::endl;

    LoggerFactory loggerFactory;
    loggerFactory.loadSettings(configFile);


    int buffSize = 10000;
    ros::init(argc, argv, "data_logger");
    ros::NodeHandle n;
    double sleepTime = 0.01;

//    vicon_log::ViconDataLogger viconDataLogger(buffSize, "viconOutput", "vicon/CAR/CAR", n, 1, "t, x, y, z, angX, angY, angZ, qx, qy, qz, qw");
//    imu_log::ImuDataLogger imuDataLogger(buffSize, "imuOutput", "imu/data", n, 1000, "t, a_x, a_y, a_z, w_x, w_y, w_z, qx, qy, qz, qw");
//    enc_log::EncDataLogger encDataLogger(buffSize, "encOutput", "forward_vel", n, 1000, "time, velFL, velFR, velBL, velBR");

    //current working directory
    boost::filesystem::path full_path(boost::filesystem::current_path());

    signal(SIGINT, signalCallback);

    while (true) {
        ros::spinOnce();
        if (flag) {
            std::cout << " \n Data logger node terminated. Saving measurements into: " << full_path << std::endl;
            break;
        }
        ros::Duration(sleepTime).sleep();
    }
    ros::shutdown();
    return 0;
}
