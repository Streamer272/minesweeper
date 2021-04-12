#include <iostream>
#include <ctime>
#include "Timer.h"

using namespace std;

Timer::Timer(int minutes_) {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    start_hour = local_time->tm_hour;
    start_min = local_time->tm_min;
    start_sec = local_time->tm_sec;

    minutes = minutes_;
}

int Timer::getTimeToEnd() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    int minutes_till_end = minutes - (local_time->tm_min - start_min);
    int seconds_till_end = 0;

    // dont ask me how it works because i dont know either
    if (start_sec > local_time->tm_sec)
        seconds_till_end = start_sec - local_time->tm_sec;

    else if (start_sec == local_time->tm_sec)
        seconds_till_end = 0;

    else if (start_sec < local_time->tm_sec) {
        minutes_till_end--;
        seconds_till_end = 60 - (local_time->tm_sec - start_sec);
    }

    return minutes_till_end * 100 + seconds_till_end;
}

string Timer::getTimeToEndAsString() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    int minutes_till_end = minutes - (local_time->tm_min - start_min);
    int seconds_till_end = 0;

    // dont ask me how it works because i dont know either
    if (start_sec > local_time->tm_sec)
        seconds_till_end = start_sec - local_time->tm_sec;

    else if (start_sec == local_time->tm_sec)
        seconds_till_end = 0;

    else if (start_sec < local_time->tm_sec) {
        minutes_till_end--;
        seconds_till_end = 60 - (local_time->tm_sec - start_sec);
    }

    return to_string(minutes_till_end) + ":" + to_string(seconds_till_end);
}

string Timer::getTimeFromStartAsString() const {
    time_t current_time;
    current_time = time(nullptr);
    tm *local_time = localtime(&current_time);

    return to_string(local_time->tm_hour - start_hour) + ":" + to_string(local_time->tm_min - start_min) + ":" +
            to_string(local_time->tm_sec - start_sec);
}
