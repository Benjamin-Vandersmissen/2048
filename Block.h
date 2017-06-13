//
// Created by Benjamin on 13/06/2017.
//

#ifndef INC_2048_BLOCK_H
#define INC_2048_BLOCK_H


class Block {
private:
    unsigned int nr = 2;
public:
    bool merge(Block *b);
    unsigned int getValue();
};


#endif //INC_2048_BLOCK_H
