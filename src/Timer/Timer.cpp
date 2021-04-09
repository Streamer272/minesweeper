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

string Timer::getTimeFromStart() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    return to_string(local_time->tm_hour - this->start_hour) + ":" + to_string(local_time->tm_min - this->start_min) + ":" + to_string(local_time->tm_sec - this->start_sec);
}

string Timer::getTimeToEndAsString() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    int minutes_till_end = this->minutes - (local_time->tm_min - this->start_min);
    int seconds_till_end = 0;

    // dont ask me how it works because i dont know either
    if (this->start_sec > local_time->tm_sec) {
        seconds_till_end = this->start_sec - local_time->tm_sec;
    }
    else if (this->start_sec == local_time->tm_sec) {
        seconds_till_end = 0;
    }
    else if (this->start_sec < local_time->tm_sec) {
        minutes_till_end--;
        seconds_till_end = 60 - (local_time->tm_sec - this->start_sec);
    }

    return to_string(minutes_till_end) + ":" + to_string(seconds_till_end);
}
