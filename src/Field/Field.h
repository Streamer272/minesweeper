#include <vector>
#include "Block.h"
#pragma once

using namespace std;

class Field {
private:
    vector<Block> field;
    bool* running;
public:
    int size;

    explicit Field(int size_, bool* running_);
    void click(int position, bool flagged);
    void draw();
    void endGame();
    void initBombs(int start_position);
    int getNumberOnNearbyBombs(int position);
};
