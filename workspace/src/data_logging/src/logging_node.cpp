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
    Eigen::Matrix<double,3,1> rot;

};

class ViconDataLogger {

public:
    ViconDataLogger(int buffSize, std::string filename) :
            m_filename(filename) {
        m_buffer.set_capacity(buffSize);
    }

    void msgCallback(geometry_msgs::TransformStamped::ConstPtr msg) {

        DataVicon dataVicon;
        dataVicon.time = msg->header.stamp.sec + msg->header.stamp.nsec * 1e-9;
        dataVicon.pos = Eigen::Matrix<double, 3, 1>(msg->transform.translation.x, msg->transform.translation.y, msg->transform.translation.z);
        Eigen::Quaternion<double> q(msg->transform.rotation.w, msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z);
        dataVicon.rot = q.toRotationMatrix().eulerAngles(0,1,2);

        m_buffer.push_back(dataVicon);

    }

    void run() {

        if (flag)
            dumpToFile();
    }

    void dumpToFile() {

        //TODO dump the actual files here
        // create and open the .csv file
        m_file.open(filename);

        // write the file headers
        m_file << "t, x, y, z, angX, angY, angZ" <<  std::endl;

//
//        for (boost::circular_buffer<Data>::const_iterator it = buffer.begin(); it != buffer.end(); it++)
//                std::cout << "(" << it->first << ", " << it->second << ")" << " ";

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

void printBuffer(const boost::circular_buffer<Data>& buffer) {
    for (boost::circular_buffer<Data>::const_iterator it = buffer.begin(); it != buffer.end(); it++)
        std::cout << "(" << it->first << ", " << it->second << ")" << " ";
    std::cout << std::endl << std::endl;
}

int main(int argc, char** argv) {

    signal(SIGINT, signalCallback);

    boost::circular_buffer<Data> buffer(5);
    ViconDataLogger viconDataLogger(5, filename);

    for (int i = 0, j = 9; i < 10; i++, j--) {
        buffer.push_back(Data(i, j));
    }

    while (true) {
        viconDataLogger.run();
        if (flag) {
            std::cout << " \n Data logger node terminated. Saving measurements into: " << filename << std::endl;
            break;
        }
    }

    return 0;
}
