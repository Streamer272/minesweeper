#include "../Field/Field.h"
#include "../Timer/Timer.h"
#pragma once

using namespace std;

class Input {
public:
    bool flagged = false;
    int position = 0;
};

class InputHandler {
private:
    static void help();
public:
    static Input takeInput(const Field& field, Timer timer);
};
