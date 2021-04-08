#include <vector>
#include "Block.h"
#pragma once

using namespace std;

class Field {
private:
    vector<Block> field;
public:
    int size;

    explicit Field(int size_);
    void Flag(int position);
    void Open(int position);
};
