//
// Created by Benjamin on 13/06/2017.
//

#include "Block.h"

bool Block::merge(Block *b) {
    if (b->getValue() == this->getValue()) {
        this->nr *= 2;
        return true;
    }
    return false;
}

unsigned int Block::getValue() {
    return this->nr;
}
