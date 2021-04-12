#pragma once

#define STATE_COVERED 1
#define STATE_UNCOVERED 2
#define STATE_FLAGGED 3
#define TYPE_EMPTY 4
#define TYPE_BOMB 5


class Block {
public:
    mutable int type = TYPE_EMPTY;
    mutable int state = STATE_COVERED;

    explicit Block(int type_ = 0, int state_ = 0);
};
