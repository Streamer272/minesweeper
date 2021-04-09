#include <iostream>
#include <string>
#include "Field/Field.h"
#include "Timer/Timer.h"
#include "InputHandler/InputHandler.h"

using namespace std;

int getSizeAndMinutes(int &size, int &minutes) {
    string size_, minutes_;
    cout << "Please enter size (length) of the field you want to play on: ";
    cin >> size_;
    cout << "Please enter minutes you want to play: ";
    cin >> minutes_;

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

void clear() {
    system("cls");
}

[[noreturn]] int main() {
    int size, minutes;
    if (getSizeAndMinutes(size, minutes)) {
        exit(1);
    }
    if (minutes < 1 || size < 1) {
        cout << "Please enter values higher than 0!" << endl;
        exit(1);
    }

    Timer timer(minutes);
    Field field(size);

    string useless;
    getline(cin, useless);

    while (true) {
        Input input = InputHandler::takeInput(field, timer);
        cout << input.position << endl;
        cout << input.flaged << endl;
//        clear();
    }
}
