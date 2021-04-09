#include <string>
#pragma once

using namespace std;

class CharMap {
public:
    string covered = "#";
    string uncovered_empty = " ";
    string flagged = "F";
    string bomb = "O";

    string getStringByState(int state) const;
};
