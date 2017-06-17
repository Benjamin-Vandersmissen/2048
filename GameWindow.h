//
// Created by benji on 17.06.17.
//

#ifndef INC_2048_GAMEWINDOW_H
#define INC_2048_GAMEWINDOW_H

#include "FL/Fl_Double_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl.H"
#include "Board.h"

class MyBox : public Fl_Box{
private:
    std::string value;
public:
    MyBox(int X, int Y, int W, int H, std::string label = "");

    void changeValue(unsigned int val);
};

class GameWindow : public Fl_Double_Window{
private:
    Board* gameBoard = NULL;
    unsigned int boardW;
    unsigned int boardH;
    std::vector<std::vector<MyBox*>> boxes;
public:
    GameWindow(int w, int h, unsigned int boardW, unsigned int boardH, const char *l = 0);

    void updateVisuals();

    int handle(int event);
};


#endif //INC_2048_GAMEWINDOW_H
