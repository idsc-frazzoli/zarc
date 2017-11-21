/*
 * ViconDataLogger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef VICON_DATA_LOGGER_H_
#define VICON_DATA_LOGGER_H_


#include <iostream>
#include <fstream>
#include <string>
#include <boost/circular_buffer.hpp>
#include <Eigen/Dense>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#include <ros/ros.h>
#include "logger.h"




struct DataVicon {

    double time;
    Eigen::Matrix<double, 3, 1> pos;
    Eigen::Matrix<double, 3, 1> rot;
    Eigen::Quaternion<double> q;
};

class ViconDataLogger : public DataLogger {

public:
    ViconDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize ) :
            m_filename("Vicon_" + filename) {
        m_buffer.set_capacity(buffSize);
        m_sub = n.subscribe(topic, queueSize, &ViconDataLogger::msgCallback, this);
    }

    virtual ~ViconDataLogger(){}

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


    void dumpToFile() override {

        // create and open the .csv file
        m_file.open(m_filename);

        // write the file headers
        m_file << "t, x, y, z, angX, angY, angZ, qx, qy, qz, qw" << std::endl;

        for (boost::circular_buffer<DataVicon>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
            m_file << it->time << ", " << it->pos(0) << ", " << it->pos(1) << ", " << it->pos(2) << ", " << it->rot(0) << ", " << it->rot(1) << ", "
                    << it->rot(2) << ", " << it->q.x() << ", " << it->q.y() << ", " << it->q.z() << ", " << it->q.w() << std::endl;

        // close the output file
        m_file.close();
    }

private:
    boost::circular_buffer<DataVicon> m_buffer;
    std::string m_filename;
    std::ofstream m_file;
    ros::Subscriber m_sub;


};


#endif /* VICON_DATA_LOGGER_H_ */
