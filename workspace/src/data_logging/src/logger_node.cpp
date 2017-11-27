/*
 * logger_node.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#include <iostream>
#include <signal.h>
#include <ros/ros.h>
#include <yaml-cpp/yaml.h>

#include "encoder_data_logger.h"
#include "vicon_data_logger.h"
#include "imu_data_logger.h"
#include "logger_factory.h"

//#define DEBUG

volatile sig_atomic_t flag = 0;

//not the greatest solution
void signalCallback(int sig) {
    flag = 1;
}

struct ConfigData {
    int buffSize;
    std::string outFileName;
    std::string rosTopicName;
    int rosQueueSize;
    std::string csvHeader;
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

    it++;

    while (it != config.end()) {

        ConfigData configData;

        configData.buffSize = it->second["buffSize"].as<int>();
        configData.outFileName = it->second["outFileName"].as<std::string>();
        configData.rosTopicName = it->second["rosTopicName"].as<std::string>();
        configData.rosQueueSize = it->second["rosQueueSize"].as<int>();
        configData.csvHeader = it->second["csvHeader"].as<std::string>();
        configData.descriptor = it->first.as<std::string>();
        params.push_back(configData);
        it++;
    }
}

void createLoggers(const std::vector<ConfigData>& configData, std::vector<LoggerFactory::loggerPtr_t>& loggers, ros::NodeHandle& n) {

    for (int i = 0; i < configData.size(); i++)
        loggers.push_back(
                LoggerFactory::newLogger(configData[i].descriptor, configData[i].buffSize, configData[i].outFileName, configData[i].rosTopicName, n,
                        configData[i].rosQueueSize, configData[i].csvHeader));
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

#ifdef DEBUG
    std::cout << configData.size() << std::endl;
    for (int i = 0; i < configData.size(); i++) {
        std::cout << configData[i].buffSize << std::endl;
        std::cout << configData[i].outFileName << std::endl;
        std::cout << configData[i].topic << std::endl;
        std::cout << configData[i].queueSize << std::endl;
        std::cout << configData[i].header << std::endl;
        std::cout << configData[i].descriptor << std::endl << std::endl << std::endl;
    }
#endif

    signal(SIGINT, signalCallback);

    while (true) {
        ros::spinOnce();
        if (flag) {
            break;
        }
        ros::Duration(sleepTime).sleep();
    }
    ros::shutdown();
    return 0;
}
