//
// Created by dusan on 17-Dec-21.
//

#ifndef MONTECARLO_STDINC_H
#define MONTECARLO_STDINC_H

#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <mutex>
#include <random>

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>

void Log(const std::string& message);
double random();

#endif //MONTECARLO_STDINC_H
