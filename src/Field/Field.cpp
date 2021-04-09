#include <iostream>
#include <cmath>
#include <ctime>
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

            if (block.state == STATE_UNCOVERED && block.type != TYPE_BOMB) {
                // TODO: add number displaying
                cout << to_string(this->getNumberOnNearbyBombs(i));
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
    cout << "You lost! Try again." << endl;
    *running = false;
}

int Field::getNumberOnNearbyBombs(int position) {
    int nearbyBombs = 0;

    if (this->field[position - this->size - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position - this->size].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position - this->size + 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position + 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position + this->size - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position + this->size].type == TYPE_BOMB)
        nearbyBombs++;
    if (this->field[position + this->size + 1].type == TYPE_BOMB)
        nearbyBombs++;

    return nearbyBombs;
}

void Field::initField(int start_position) const {
    const int numberOfBombs = floor(this->size * this->size / 10);
    int numberOfUncovered = floor(this->size * this->size / 10);
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    numberOfUncovered += floor(this->size * this->size * 0.25 * rand()); // NOLINT(cert-msc50-cpp)

    // TODO: actually use these numbers and init field
}
