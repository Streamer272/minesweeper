#include <iostream>
#include <cmath>
#include <ctime>
#include "Block.h"
#include "CharMap.h"
#include "Field.h"

using namespace std;

Field::Field(int size_, bool* running_) {
    for (int i = 0; i < size_*size_; i++) {
        const Block block;
        field.push_back(block);
    }

    size = size_;
    running = running_;
}

void Field::click(int position, bool flagged) {
    cout << "field clock triggered" << endl;

    if (flagged)
        field[position].state = STATE_FLAGGED;

    else
        field[position].state = STATE_UNCOVERED;
}

void Field::draw() {
    bool endGameProtocol = false;

    int index = 0;
    for (auto block : field) {
        if (block.state == STATE_UNCOVERED) {
            if (block.type == TYPE_EMPTY)
                    cout << to_string(getNumberOnNearbyBombs(index));

            else if (block.type == TYPE_BOMB) {
                cout << CHAR_BOMB;
                endGameProtocol = true;
            }
        }
        else if (block.state == STATE_FLAGGED)
            cout << CHAR_FLAGGED;

        else if (block.state == STATE_COVERED)
            cout << CHAR_COVERED;

        cout << " ";

        index++;

        if (index % size == 0 && index != 0)
            cout << endl;
    }

    cout << index << endl;

    if (endGameProtocol) {
        endGame();
    }
}

void Field::endGame() {
    cout << "You lost! Try again." << endl;
    *running = false;
}

int Field::getNumberOnNearbyBombs(int position) {
    int nearbyBombs = 0;

    if (field[position - size - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position - size].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position - size + 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position + 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position + size - 1].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position + size].type == TYPE_BOMB)
        nearbyBombs++;
    if (field[position + size + 1].type == TYPE_BOMB)
        nearbyBombs++;

    return nearbyBombs;
}

void Field::initField(int start_position) const {
    const int numberOfBombs = floor(size * size / 10);
    int numberOfUncovered = floor(size * size / 10);
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    numberOfUncovered += floor(size * size * 0.25 * rand()); // NOLINT(cert-msc50-cpp)

    // TODO: actually use these numbers and init field
}
