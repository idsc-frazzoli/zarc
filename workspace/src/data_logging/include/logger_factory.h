/*
 * logger_factory.h
 *
 *  Created on: Nov 25, 2017
 *      Author: jelavice
 */

#ifndef LOGGER_FACTORY_H_
#define LOGGER_FACTORY_H_


#include "logger.h"
#include <memory>

class LoggerFactory
 {
 public:

    static enum LoggerType {
        VICON,
        IMU,
        ENCODER
    };

    typedef std::unique_ptr<DataLogger> loggerPtr_t;

     static DataLogger NewLogger(LoggerType id)
     {
         if(id == "laptop")
             return new Laptop;
         if(id == "desktop")
             return new Desktop;
         return NULL;
     }
 };


#endif /* LOGGER_FACTORY_H_ */
