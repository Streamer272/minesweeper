#include <iostream>
#include <ctime>
#include "Timer.h"

using namespace std;

Timer::Timer() {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    this->start_hour = local_time->tm_hour;
    this->start_min = local_time->tm_min;
    this->start_sec = local_time->tm_sec;
}

int Timer::getTimeFromStart(const string& type) const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    if (type == "sec") {
        return local_time->tm_sec - this->start_sec;
    }
    else if (type == "min") {
        return local_time->tm_min - this->start_min;
    }
    else if (type == "hour") {
        return local_time->tm_hour - this->start_hour;
    }
    else {
        return -1;
    }
}
