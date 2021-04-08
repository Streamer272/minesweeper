#include "Block.h"
#include "Field.h"

using namespace std;

Field::Field(int size_) {
    for (int i = 0; i < size_*size_; i++) {
        this->field.emplace_back(TYPE_EMPTY, STATE_COVERED);
    }
    this->size = size_;
}

void Field::Flag(int position) {
    this->field[position].state = STATE_FLAGED;
}

void Field::Open(int position) {
    this->field[position].state = STATE_UNCOVERED;
}
