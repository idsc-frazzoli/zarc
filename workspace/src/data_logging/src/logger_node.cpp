/*
 * logger_node.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */




/*
 * logging_node.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: jelavice
 */

// inlcude iostream and string libraries
#include <iostream>
#include <Eigen/Dense>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ros/ros.h>
#include <boost/filesystem.hpp>

#include "encoder_data_logger.h"
#include "imu_data_logger.h"
#include "vicon_data_logger.h"





volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}


//don't need this unless I want to do some dynamic loading
//class LoggerFactory {
//
//public:
//
//    enum LoggerType {
//        VICON,
//        IMU,
//        ENCODER
//    };
//
//};




//#include <libgen.h>
//
//ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
//const char *path;
//if (count != -1) {
//    path = dirname(result);
//}

int main(int argc, char** argv) {

    int buffSize = 10000;
    ros::init(argc, argv, "data_logger");
    ros::NodeHandle n;

    ViconDataLogger viconDataLogger(buffSize, "viconExampleOutput",  "vicon/CAR/CAR", n, 1 );
    //ImuDataLogger imuDataLogger(buffSize, "imuOutput",  "imu/data", n, 1000 );
    //EncDataLogger encDataLogger(buffSize, "encOutput",  "forward_vel", n, 1000 );

    //current working directory
    boost::filesystem::path full_path( boost::filesystem::current_path() );

    signal(SIGINT, signalCallback);

    while (true) {
        ros::spinOnce();
        if (flag) {
            std::cout << " \n Data logger node terminated. Saving measurements into: " << full_path << std::endl;
           viconDataLogger.dumpToFile();
            //imuDataLogger.dumpToFile();
            //encDataLogger.dumpToFile();
            break;
        }
        ros::Duration(0.01).sleep();
    }
    ros::shutdown();
    return 0;
}
