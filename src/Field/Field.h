#include <vector>
#include "Block.h"
#pragma once

using namespace std;

class Field {
    /*
     * field class for tracking, displaying and changing field
     * */
private:
    vector<Block> field = {};  // field vector (with all positions in it)
    bool* running;  // if game ends, this will be false
public:
    int size;  // length of the field (length and width are the same)

    explicit Field(int size_, bool* running_);
    void click(int position, bool flagged);  // uncovers or flags certain position
    void draw();  // draws field in console
    void endGame();  // ends game
    void initField(int startPosition) const;  // first click, creates bombs and empty start
    int getNumberOnNearbyBombs(int position);  // returns number or nearby bombs
    bool checkFullField();  // checks for full field (if every single position is uncovered or flagged)
    int getRandomPosAroundPos(int position) const;  //  returns random position around certain position
};
