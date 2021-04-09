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

int startGame() {
    int size, minutes;
    if (getSizeAndMinutes(size, minutes)) {
        return 1;
    }
    if (minutes < 1 || size < 1) {
        cout << "Please enter values higher than 0!" << endl;
        return 1;
    }

    bool running = true;

    Timer timer(minutes);
    Field field(size, &running);

    string useless;
    getline(cin, useless);

    while (running) {
        field.draw();
        Input input = InputHandler::takeInput(field, timer);
        field.click(input.position, input.flagged);
//        clear();
    }

    return 0;
}

[[noreturn]] int main() {
    while (true) {
        startGame();
    }
}
