#include <ctime>
#pragma once

using namespace std;

class Timer {
private:
    int start_hour, start_min, start_sec;
    int minutes;
public:
    explicit Timer(int minutes_);
    string getTimeFromStartAsString() const;
    string getTimeToEndAsString() const;
    int getTimeToEnd() const;
};
