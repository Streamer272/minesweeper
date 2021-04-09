#include <iostream>
#include "Block.h"
#include "CharMap.h"
#include "Field.h"

using namespace std;

Field::Field(int size_, bool* running_) {
    for (int i = 0; i < size_*size_; i++) {
        this->field.emplace_back(TYPE_EMPTY, STATE_COVERED);
    }

    this->size = size_;
    this->running = running_;
}

void Field::click(int position, bool flagged) {
    if (flagged) {
        this->field[position].state = STATE_FLAGGED;
    }
    else {
        this->field[position].state = STATE_UNCOVERED;
    }
}

void Field::draw() {
    CharMap charMap;
    bool endGameProtocol = false;

    for (int x = 0; x < this->size; x++) {
        for (int i = 0; i < this->size; i++) {
            Block block = this->field[i];

            if (block.state == STATE_UNCOVERED) {
                // TODO: add number displaying
            }
            else {
                if (block.type == TYPE_BOMB) {
                    endGameProtocol = true;
                }

                cout << charMap.getStringByState(block.state);
            }

            cout << " ";
        }
        cout << endl;
    }

    if (endGameProtocol) {
        this->endGame();
    }
}

void Field::endGame() {
    cout << "You clicked on a bomb! You lost! Try again." << endl;
    *running = false;
}

