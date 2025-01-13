#pragma once

#include <string>
#include "Pieces.hpp"

class Board
{
private:
    Board();
    static Board* instance;
    char turncolour{'W'};
    int ranks[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int wking_row, wking_col, bking_row, bking_col;
    Piece* position[8][8]{nullptr};

public:
    static Board* getInstance();
    ~Board();
    void printBoard();
    char getTurnColour();
    void alternateTurn();
    void startMessage();
    void endMessageWin(std::string& player);
    void endMessageDraw();
    // move-related functions
    void makeMove();
    void inputChecker(std::string& input);
    int inputConverter(char& i, int mode);
    // king-related functions
    void findKings(Piece* temp[8][8]);
    bool isKingCheck(Piece* temp[8][8], char& king_colour);
    bool willKingCheck(int irow, int icol, int frow, int fcol, char king_colour);
    bool canKingMove(char king_colour);
    bool canAnyMove();
    bool isCheckmate();
    bool isStalemate();
    // special moves
    void pawnPromotion(int row, int col);
    bool castling(char king_colour, int fcol);
};