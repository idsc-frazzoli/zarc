/*
 * logger.h
 *
 *  Created on: Nov 21, 2017
 *      Author: jelavice
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>


class DataLogger {

public:
    virtual void dumpToFile() = 0;

    virtual ~DataLogger() {}

};



#endif /* LOGGER_H_ */
