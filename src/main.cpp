#include <iostream>
#include <string>
#include <unistd.h>
#include "Field/Field.h"
#include "Timer/Timer.h"

using namespace std;

int getSizeAndMinutes(int &size, int &minutes) {
    string size_, minutes_;
    cout << "Please enter size (length) of the field you want to play on: ";
    cin >> size;
    cout << "Please enter minutes you want to play: ";
    cin >> minutes;

    try {
        stoi(size_);
    }
    catch (const invalid_argument &e) {
        cout << "Field size isn't number!!" << endl;
        return 1;
    }
    try {
        stoi(minutes_);
    }
    catch (const invalid_argument &e) {
        cout << "Minutes isn't number!!" << endl;
        return 1;
    }

    size = stoi(size_);
    minutes = stoi(minutes_);

    return 0;
}


int main() {
    int size, minutes;
    if (getSizeAndMinutes(size, minutes)) {
        return 1;
    }

    Timer timer;
    Field field(size);

    return 0;
}
