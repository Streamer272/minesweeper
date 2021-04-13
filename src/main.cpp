/*
 * author: Streamer272
 * project start date: 8/04/2021
 * project end date: --/--/----
 * * comments are in source files
 * */


#include <iostream>
#include <string>
#include "Field/Field.h"
#include "Timer/Timer.h"
#include "InputHandler/InputHandler.h"

using namespace std;

int getStartSizeAndMinutes(int &size, int &minutes) {
    /*
     * this function asks for start size and start minutes and returns them
     * */

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
    /*
     * this function clears windows console
     * */

    cout << "CLEAR" << endl;

//    system("cls");
}

int startGame() {
    /*
     * starts minesweeper game
     * */

    int size, minutes;
    if (getStartSizeAndMinutes(size, minutes)) {
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

    cout << "drawing field" << endl;
    field.draw();

    cout << "taking input" << endl;
    Input firstInput = InputHandler::takeInput(field, timer);
    cout << "initing field" << endl;
    field.initField(firstInput.position);

    clear();

    while (running) {
        if (field.checkFullField()) {
            cout << "Congratulations, you won in time " << timer.getTimeFromStartAsString() << "!" << endl;
            return 0;
        }

        if (timer.getTimeToEnd() < 1) {
            cout << "Time expired!" << endl;
            return 0;
        }

        field.draw();

        Input input = InputHandler::takeInput(field, timer);
        field.click(input.position, input.flagged);

        clear();
    }

    return 0;
}

int main() {
    /*
     * runs whole code
     * */

    bool autoplay = false;

    while (true) {
        startGame();

        bool done = false;

        if (!autoplay) {
            do {
                string command;
                cout << "Game ended, write \":r\" to restart and \":e\" to exit: "; // NOLINT(modernize-raw-string-literal)
                cin >> command;

                // exit
                if (command == ":e") {
                    exit(0);
                }

                // restart
                else if (command == ":r") {
                    done = true;
                }

                // auto restart
                else if (command == ":ar") {
                    autoplay = true;
                }

                else {
                    cout << "Please enter valid command!" << endl;
                }
            } while (!done);
        }
    }
}
