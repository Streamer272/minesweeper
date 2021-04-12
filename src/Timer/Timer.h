#include <ctime>
#pragma once

using namespace std;

class Timer {
    /*
     * timer class for using time
     * */
private:
    int start_hour, start_min, start_sec;  // start of timer
    int minutes;  // minutes length of timer
public:
    explicit Timer(int minutes_);
    string getTimeFromStartAsString() const;  // returns string type of time
    string getTimeToEndAsString() const;
    int getTimeToEnd() const;
};
