/*
 * vicon_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "vicon_data_logger.h"


//TODO do this in the base class
ViconDataLogger::ViconDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize, std::string header):
ViconDataLogger::BASE(buffSize,filename, queueSize, header)
{

    m_sub = n.subscribe(topic, queueSize, &ViconDataLogger::msgCallback, this);
}

void ViconDataLogger::msgCallback(geometry_msgs::TransformStamped::ConstPtr msg) {

    static double timeOffset = -1;

    if (timeOffset < 0)
        timeOffset = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9;
    //TODO move this to a different function;
    DataVicon dataVicon;
    dataVicon.time = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9 - timeOffset;
    dataVicon.pos = Eigen::Matrix<double, 3, 1>(msg->transform.translation.x, msg->transform.translation.y, msg->transform.translation.z);
    dataVicon.q = Eigen::Quaternion<double>(msg->transform.rotation.w, msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z);
    dataVicon.rot = dataVicon.q.toRotationMatrix().eulerAngles(0, 1, 2);

    //TODO push the data in the buffer

}


