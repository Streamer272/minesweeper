#include "Block.h"

Block::Block(int type_, int state_) {
    // If it is 0 (default) nothing will happen else class members will be set to that value

    if (type_) {
        this->type = type_;
    }
    if (state_) {
        this->state = state_;
    }
}
