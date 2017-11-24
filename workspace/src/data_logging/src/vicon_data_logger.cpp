/*
 * vicon_data_logger.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include "vicon_data_logger.h"
#include <ctime>

//TODO do this in the base class
ViconDataLogger::ViconDataLogger(int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize) :
        m_filename(filename) {
    m_buffer.set_capacity(buffSize);
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

    m_buffer.push_back(dataVicon);
}

//TODO move to base
void ViconDataLogger::dumpToFile1() {


    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
    std::string time(buffer);

    m_filename = m_filename + "_" + time + ".csv";

    std::ofstream file;

    // create and open the .csv file
    file.open(m_filename);

    // write the file headers
    file << "t, x, y, z, angX, angY, angZ, qx, qy, qz, qw" << std::endl;

    for (boost::circular_buffer<DataVicon>::const_iterator it = m_buffer.begin(); it != m_buffer.end(); it++)
        file << it->time << ", " << it->pos(0) << ", " << it->pos(1) << ", " << it->pos(2) << ", " << it->rot(0) << ", " << it->rot(1) << ", " << it->rot(2)
                << ", " << it->q.x() << ", " << it->q.y() << ", " << it->q.z() << ", " << it->q.w() << std::endl;

    // close the output file
    file.close();
}
