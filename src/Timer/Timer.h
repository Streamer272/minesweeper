#include <ctime>
#pragma once

using namespace std;

class Timer {
private:
    int start_hour, start_min, start_sec;
public:
    explicit Timer();
    int getTimeFromStart(const string& type = "min") const;
};
