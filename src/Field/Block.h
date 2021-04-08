#pragma once

#define STATE_COVERED 1
#define STATE_UNCOVERED 2
#define STATE_FLAGED 3
#define TYPE_EMPTY 4
#define TYPE_BOMB 5


class Block {
public:
    int type = 0;
    int state = 0;

    explicit Block(int type_ = 0, int state_ = 0);
};
