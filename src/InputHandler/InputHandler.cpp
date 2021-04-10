#include <iostream>
#include "../Field/Field.h"
#include "InputHandler.h"

using namespace std;

Input InputHandler::takeInput(const Field& field, Timer timer) {
    string position;
    cout << "Enter position or \":h\" for help: ";
    getline(cin, position);

    if (position == ":h") {
        help();
        return takeInput(field, timer);
    }

    else if (position == ":e")
        exit(0);

    else if (position == ":t")
        cout << timer.getTimeToEndAsString() << endl;
        return takeInput(field, timer);

    Input input; // NOLINT(cppcoreguidelines-pro-type-member-init)

    if (position.find("f") != string::npos)
        input.flagged = true;

    string x, y;
    bool after_dash = false;
    for (char i : position) {
        string iS(1, i);

        if (iS == " ") {}
        else if (iS == "f") {}
        else if (!after_dash) {
            if (iS == "-")
                after_dash = true;

            else
                x += iS;
        }
        else
            y += iS;
    }

    try {
        input.position = (stoi(x) - 1) * field.size + (stoi(y) - 1);

        if (stoi(x) - 1 < 0)
            throw invalid_argument("");
        if (stoi(y) - 1 < 0)
            throw invalid_argument("");
    }
    catch (const invalid_argument& e) {
        cout << "Please enter valid command!" << endl;
        return takeInput(field, timer);
    }

    return input;
}

void InputHandler::help() {
    cout << "You can enter position like this: \"x-y\" where x is vertical and y is diagonal. Field positions"
            " start at 1" << endl;
    cout << "Enter \"f\" before position to apply flagged on target, "
            "like this: \"f x-y\"" << endl; // NOLINT(modernize-raw-string-literal)
    cout << "Enter \":t\" to get time you need to finish in" << endl;
    cout << "Enter \":e\" to quit game" << endl;
}
