/*
 * logger_factory.h
 *
 *  Created on: Nov 25, 2017
 *      Author: jelavice
 */

#ifndef LOGGER_FACTORY_H_
#define LOGGER_FACTORY_H_


#include "logger.h"
#include "vicon_data_logger.h"
#include <memory>

class LoggerFactory
 {
 public:

    static enum LoggerType {
        VICON,
        IMU,
        ENCODER
    };

    typedef std::unique_ptr<IDataLogger> loggerPtr_t;

     static DataLogger NewLogger(LoggerType id, int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize, std::string header)
     {
         if(id == VICON)
             return std::unique_ptr<IDataLogger> (new ViconDataLogger(buffSize, filename, topic, n, queueSize, header));

         return NULL;
     }
 };


#endif /* LOGGER_FACTORY_H_ */
