#include "CharMap.h"
#include "Block.h"

using namespace std;

string CharMap::getStringByState(int state) const {
    if (state == STATE_FLAGGED) {
        return this->flagged;
    }
    else if (state == STATE_COVERED) {
        return this->covered;
    }
    else {
        return "";
    }
}
