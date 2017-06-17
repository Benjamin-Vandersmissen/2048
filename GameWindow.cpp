//
// Created by benji on 17.06.17.
//

#include "GameWindow.h"

GameWindow::GameWindow(int w, int h, unsigned int boardW, unsigned int boardH, const char *l) : Fl_Double_Window(w, h, l), boardW(boardW), boardH(boardH){
    gameBoard = new Board(boardW , boardH);

    unsigned int topLeftX = 0;
    unsigned int topLeftY = 0;
    unsigned int XOffset = w/boardW;
    unsigned int YOffset = h/boardH;

    for(unsigned int a = 0 ; a < boardW ; a++){
        std::vector<MyBox*> row;
        for(unsigned int b = 0; b < boardH; b++){
            MyBox* box = new MyBox(topLeftX+a*XOffset, topLeftY+b*YOffset, XOffset, YOffset);
            box->box(FL_BORDER_BOX);
            row.push_back(box);
        }
        boxes.push_back(row);

    }
    this->gameBoard->addNewBlock();
    this->updateVisuals();
    this->end();
    this->show();
}

void GameWindow::updateVisuals() {
    for(unsigned int a = 0; a < boardW; a++){
        for(unsigned int b = 0; b < boardH; b++){
            if ((*gameBoard)(a,b) != NULL){ //a block is at the current position
                boxes[a][b]->changeValue((*gameBoard)(a,b)->getValue());
            }
            else{
                boxes[a][b]->changeValue(0);
            }
        }
    }
    this->redraw();
}

int GameWindow::handle(int event) {
    switch(event){
        case FL_KEYBOARD:
            switch(Fl::event_key()){
                case FL_Down:
                    this->gameBoard->moveDown();
                    this->gameBoard->addNewBlock();
                    this->updateVisuals();
                    break;
                case FL_Up:
                    this->gameBoard->moveUp();
                    this->updateVisuals();
                    this->gameBoard->addNewBlock();
                    break;
                case FL_Left:
                    this->gameBoard->moveLeft();
                    this->gameBoard->addNewBlock();
                    this->updateVisuals();
                    break;
                case FL_Right:
                    this->gameBoard->moveRight();
                    this->gameBoard->addNewBlock();
                    this->updateVisuals();
                    break;
                default:
                    break;
            }
        default:
            break;
    }
    return Fl_Window::handle(event);
}


MyBox::MyBox(int X, int Y, int W, int H, std::string label) : Fl_Box(X, Y, W, H) {
    this->value = label;
    this->label(this->value.c_str());
}

void MyBox::changeValue(unsigned int val) {
    this->value = std::to_string(val);
    if (val == 0)
        this->label("");
    else
        this->label(value.c_str());

}
