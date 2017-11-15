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



// create an ofstream for the file output (see the link on streams for
// more info)
std::ofstream file;
// create a name for the file output
std::string filename = "exampleOutput.csv";

// create some variables for demonstration
int i;
int A;
int B;
int C;


struct DataVicon {

    double time;
    Eigen::Matrix<double,3,1> pos;
    Eigen::Quaternion<double> q;
};

class ViconDataLogger {


    ViconDataLogger(int buffSize) {
        m_buffer.set_capacity(buffSize);
    }

    void msgCallback(geometry_msgs::TransformStamped::ConstPtr msg){

        DataVicon dataVicon;
        dataVicon.time = msg->header.stamp.sec + msg->header.stamp.nsec*1e-9;
        dataVicon.pos = Eigen::Matrix<double,3,1>(msg->transform.translation.x, msg->transform.translation.y, msg->transform.translation.z);
        dataVicon.q = Eigen::Quaternion<double> (msg->transform.rotation.x, msg->transform.rotation.y, msg->transform.rotation.z, msg->transform.rotation.w);
        m_buffer.push_back(dataVicon);

    }

private:
    boost::circular_buffer<DataVicon> m_buffer;

};

struct Data {
    Data (int a, int b){first  = a; second = b;}
    int first;
    int second;
};
void printBuffer (const boost::circular_buffer<Data>& buffer) {
    for (boost::circular_buffer<Data>::const_iterator it = buffer.begin(); it != buffer.end(); it++)
        std::cout << "(" << it->first << ", " << it->second << ")" << " ";
    std::cout << std::endl << std::endl;
}






int main(int argc, char** argv)
{




    boost::circular_buffer<Data> buffer(5);


    for (int i=0, j=9; i < 10; i++, j--){
        buffer.push_back(Data(i,j));
        printBuffer(buffer);
    }



    // create and open the .csv file
    file.open(filename);

    // write the file headers
    file << "Column A" << "," << "Column B" << "Column C" << std::endl;

    // i is just a variable to make numbers with in the file
    i = 1;

    // write data to the file
    for (int counter = 0; counter <  10; counter++)
    {
        // make some data
        A = i + 5;
        B = i + 10;
        C = i + 20;

        // write the data to the output file
        file << A << "," << B << "," << C << std::endl;

        // increase i
        i = i * 5;
    }

    // close the output file
    file.close();
    return 0;
}
