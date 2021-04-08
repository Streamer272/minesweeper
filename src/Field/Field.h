#include <vector>
#include "Block.h"
#pragma once

using namespace std;

class Field {
private:
    vector<Block> field;
public:
    explicit Field(int size);
    void Flag(int position);
    void Open(int position);
};
