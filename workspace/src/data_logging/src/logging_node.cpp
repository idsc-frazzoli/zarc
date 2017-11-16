/*
 * logging_node.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: jelavice
 */

// inlcude iostream and string libraries
#include <iostream>
#include <fstream>
#include <string>
#include <boost/circular_buffer.hpp>
#include <geometry_msgs/TransformStamped.h>
#include <Eigen/Dense>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ros/ros.h>

volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}

// create a name for the file output
std::string filename = "exampleOutput.csv";

struct DataVicon {

    double time;
    Eigen::Matrix<double, 3, 1> pos;
    Eigen::Matrix<double, 3, 1> rot;
    Eigen::Quaternion<double> q;
};

class ViconDataLogger {

public:
    ViconDataLogger(int buffSize, std::string filename) :
            m_filename(filename) {
        m_buffer.set_capacity(buffSize);

    }

    void msgCallback(geometry_msgs::TransformStamped::ConstPtr msg) {

        static double timeOffset = -1;

        if (timeOffset < 0)
            timeOffset = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9;

        DataVicon dataVicon;
        dataVicon.time = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9 - timeOffset;
        dataVicon.pos = Eigen::Matrix<double, 3, 1>(msg->transform.translation.x, msg->transform.translation.y, msg->transform.translation.z);
        dataVicon.q = Eigen::Quaternion<double>(msg->transform.rotation.w, msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z);
        dataVicon.rot = dataVicon.q.toRotationMatrix().eulerAngles(0, 1, 2);

        m_buffer.push_back(dataVicon);
    }

    void run() {

        ros::spinOnce();
        ros::Duration(0.01).sleep();

    }

    void dumpToFile() {

        // create and open the .csv file
        m_file.open(filename);

        // write the file headers
        m_file << "t, x, y, z, angX, angY, angZ, qx, qy, qz, qw" << std::endl;

        for (boost::circular_buffer<DataVicon>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
            m_file << it->time << ", " << it->pos(0) << ", " << it->pos(1) << ", " << it->pos(2) << ", "
            << it->rot(0) << ", " << it->rot(1) << ", " << it->rot(2) <<", "
            << it->q.x() << ", " << it->q.y() << ", " << it->q.z() << ", " << it->q.w() << std::endl;

        // close the output file
        m_file.close();
    }

private:
    boost::circular_buffer<DataVicon> m_buffer;
    std::string m_filename;
    std::ofstream m_file;

};

struct Data {
    Data(int a, int b) {
        first = a;
        second = b;
    }
    int first;
    int second;
};

int main(int argc, char** argv) {


    ViconDataLogger viconDataLogger(10000, filename);

    ros::init(argc, argv, "data_logger");
    ros::NodeHandle n;
    ros::Subscriber sub;
    sub = n.subscribe("vicon/CAR/CAR", 1, &ViconDataLogger::msgCallback, &viconDataLogger);


    signal(SIGINT, signalCallback);

    while (true) {
        viconDataLogger.run();
        if (flag) {
            std::cout << " \n Data logger node terminated. Saving measurements into: " << filename << std::endl;
            viconDataLogger.dumpToFile();
            break;
        }
    }
    ros::shutdown();
    return 0;
}
