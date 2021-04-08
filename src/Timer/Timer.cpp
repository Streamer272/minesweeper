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

string Timer::getTimeToEndAsString() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    int minutes_till_end = this->minutes - (local_time->tm_min - this->start_min);
    int seconds_till_end = 0;

    // TODO: finish seconds implementation
    if (this->start_sec <= local_time->tm_sec) {
        seconds_till_end = 60 + this->start_sec - local_time->tm_sec;
    }
    else {
        seconds_till_end = 60 + this->start_sec;
    }

    return to_string(minutes_till_end) + ":" + to_string(seconds_till_end);
}
