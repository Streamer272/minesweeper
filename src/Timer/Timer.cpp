#include <iostream>
#include <ctime>
#include "Timer.h"

using namespace std;

Timer::Timer(int minutes_) {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    this->start_hour = local_time->tm_hour;
    this->start_min = local_time->tm_min;
    this->start_sec = local_time->tm_sec;

    this->minutes = minutes_;
}

int Timer::getTimeFromStart() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    return (local_time->tm_hour - this->start_hour) * 10000 + (local_time->tm_min - this->start_min) * 100 + (local_time->tm_sec - this->start_sec);
}

int Timer::getTimeToEnd() const {
    int timeFromStart = this->getTimeFromStart();

    return this->minutes - timeFromStart;
}
