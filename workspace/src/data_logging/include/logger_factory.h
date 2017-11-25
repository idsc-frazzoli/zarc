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
#include "imu_data_logger.h"
#include "encoder_data_logger.h"
#include <memory>

class LoggerFactory {
public:

    typedef std::unique_ptr<IDataLogger> loggerPtr_t;

    static loggerPtr_t newLogger(std::string descriptor, int buffSize, std::string filename, std::string topic, ros::NodeHandle& n, int queueSize,
            std::string header) {
        if (descriptor == "vicon_logger")
            return loggerPtr_t(new vicon_log::ViconDataLogger(buffSize, filename, topic, n, queueSize, header));
        if (descriptor == "imu_logger")
            return loggerPtr_t(new imu_log::ImuDataLogger(buffSize, filename, topic, n, queueSize, header));
        if (descriptor == "enc_logger")
            return loggerPtr_t(new enc_log::EncDataLogger(buffSize, filename, topic, n, queueSize, header));

        return loggerPtr_t(nullptr);
    }
};

#endif /* LOGGER_FACTORY_H_ */
