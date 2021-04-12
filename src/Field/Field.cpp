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

    if (flagged) {
        field[position].state = STATE_FLAGGED;
    }

    else {
        field[position].state = STATE_UNCOVERED;
    }
}

void Field::draw() {
    cout << "drawing" << endl;

    bool endGameProtocol = false;

    int index = 0;
    for (auto block : field) {
        if (block.state == STATE_UNCOVERED) {
            if (block.type == TYPE_EMPTY) {
                cout << to_string(getNumberOnNearbyBombs(index));
            }

            else if (block.type == TYPE_BOMB) {
                cout << CHAR_BOMB;
                endGameProtocol = true;
            }
        }
        else if (block.state == STATE_FLAGGED) {
            cout << CHAR_FLAGGED;
        }

        else if (block.state == STATE_COVERED) {
            cout << CHAR_COVERED;
        }

        cout << " ";

        index++;

        if (index % size == 0 && index != 0) {
            cout << endl;
        }
    }

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

    if (field[position - size - 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position - size].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position - size + 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position - 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position + 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position + size - 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position + size].type == TYPE_BOMB) {
        nearbyBombs++;
    }
    if (field[position + size + 1].type == TYPE_BOMB) {
        nearbyBombs++;
    }

    return nearbyBombs;
}

void Field::initField(int startPosition) const {
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    int numberOfUncovered = floor(size * size / 10);
    numberOfUncovered += floor(size * size * 0.25 * rand()); // NOLINT(cert-msc50-cpp)
    const int numberOfBombs = floor(size * size / 10);

    int lastUncoverPosition = getRandomPosAroundPos(startPosition);
    for (int i = 0; i < numberOfUncovered; i++) {
        field[lastUncoverPosition].state = STATE_UNCOVERED;
        lastUncoverPosition = getRandomPosAroundPos(lastUncoverPosition);
    }

    for (int i = 0; i < numberOfBombs; i++) {
        while (true) {
            const int randomPos = floor(rand() * (size * size)); // NOLINT(cert-msc50-cpp)

            if (field[randomPos].state == STATE_COVERED) {
                field[randomPos].type = TYPE_BOMB;
                break;
            }
        }
    }
}

bool Field::checkFullField() {
    for (Block block : field) { // NOLINT(readability-use-anyofallof)
        if (block.type == STATE_FLAGGED && block.type != TYPE_BOMB) {
            return false;
        }

        if (block.state == STATE_COVERED) {
            return false;
        }
    }

    return true;
}

int Field::getRandomPosAroundPos(int position) const {
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    const int randNum = floor(rand() * 7); // NOLINT(cert-msc50-cpp)

    switch (randNum) {
        case 0:
            return position - size - 1;
        case 1:
            return position - size;
        case 2:
            return position - size + 1;
        case 3:
            return position - 1;
        case 4:
            return position + 1;
        case 5:
            return position + size - 1;
        case 6:
            return position + size;
        case 7:
            return position + size + 1;
        default:
            return 0;
    }
}
