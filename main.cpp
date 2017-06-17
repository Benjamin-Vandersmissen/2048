#include <iostream>
#include "Board.h"
#include "GameWindow.h"
#include "FL/Fl.H"

int main() {
    GameWindow* win = new GameWindow(400, 400, 4, 4,"Game");
    return Fl::run();
}