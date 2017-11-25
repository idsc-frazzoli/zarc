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
#include "logger_factory.h"

volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}

struct ConfigData {
    int buffSize;
    std::string outFileName;
    std::string topic;
    int queueSize;
    std::string header;
    std::string descriptor;
};

void loadSettings(std::string filename, double& sleepTime, std::vector<ConfigData>& params) {
    YAML::Node config = YAML::LoadFile(filename);

    if (config.IsNull())
        throw std::runtime_error("YAML couldn't find: " + filename); //File Not Found?

    YAML::const_iterator it = config.begin();
    std::string key = it->first.as<std::string>();
    if (key != "logger_node")
        throw std::runtime_error("Settings for the logger node not specified");

    sleepTime = it->second.as<double>();

    it++;
    while (it != config.end()) {

        //TODO fix this, second is not god
        ConfigData configData;
        configData.buffSize = it->second["buffSize"].as<int>();
        configData.outFileName = it->second["outFileName"].as<std::string>();
        configData.topic = it->second["topicName"].as<std::string>();
        configData.queueSize = it->second["rosSubQueueSize"].as<int>();
        configData.header = it->second["header"].as<std::string>();
        configData.descriptor = it->first.as<std::string>();
        params.push_back(configData);
        it++;
    }
}

void createLoggers(const std::vector<ConfigData>& configData, std::vector<LoggerFactory::loggerPtr_t>& loggers, ros::NodeHandle& n){

    for (int i=0; i < configData.size(); i++)
        loggers.push_back(LoggerFactory::newLogger(configData[i].descriptor, configData[i].buffSize,
                configData[i].outFileName, configData[i].topic, n, configData[i].queueSize, configData[i].header));
}

int main(int argc, char** argv) {

    if (argc < 2)
        throw std::runtime_error("No config file provided");

    ros::init(argc, argv, "data_logger");
    ros::NodeHandle n;
    double sleepTime;
    std::string configFile(argv[1]);
    std::vector<LoggerFactory::loggerPtr_t> loggers;
    std::vector<ConfigData> configData;


    loadSettings(configFile, sleepTime, configData);
    createLoggers(configData, loggers, n);


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
