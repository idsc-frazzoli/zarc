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

#include "encoder_data_logger.h"
#include "imu_data_logger.h"
#include "vicon_data_logger.h"





volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}

// create a name for the file output
std::string filename = "exampleOutput.csv";



int main(int argc, char** argv) {

    int buffSize = 10000;
    ros::init(argc, argv, "data_logger");
    ros::NodeHandle n;

    ViconDataLogger viconDataLogger(buffSize, filename,  "vicon/CAR/CAR", n, 1 );
    ImuDataLogger imuDataLogger(buffSize, filename,  "imu/data", n, 1000 );
    EncDataLogger encDataLogger(buffSize, filename,  "forward_vel", n, 1000 );


    signal(SIGINT, signalCallback);

    while (true) {
        ros::spinOnce();
        if (flag) {
            std::cout << " \n Data logger node terminated. Saving measurements into: " << filename << std::endl;
            viconDataLogger.dumpToFile();
            imuDataLogger.dumpToFile();
            encDataLogger.dumpToFile();
            break;
        }
        ros::Duration(0.01).sleep();
    }
    ros::shutdown();
    return 0;
}
