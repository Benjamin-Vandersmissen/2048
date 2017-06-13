#include <iostream>
#include "Board.h"


int main() {
    Board b(4,4);
    std::cerr << b << std::endl;
    b.moveRight();
    std::cerr << b << std::endl;
    return 0;
}