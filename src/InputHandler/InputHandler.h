#include "../Field/Field.h"
#include "../Timer/Timer.h"
#pragma once

using namespace std;

class Input {
    /*
     * class for input
     * */
public:
    bool flagged = false;  // is position flagged
    int position = 0;  // position
};

class InputHandler {
    /*
     * class for input handling
     * */
private:
    static void help();  // prints help (basic commands and input)
public:
    static Input takeInput(const Field& field, Timer timer);  // takes input and returns input type class
};
