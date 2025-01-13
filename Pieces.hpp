#pragma once

class Piece
{
protected:
    char id, colour;
    bool status{false}; // if piece has moved or not
public:
    Piece(char c, char i) : colour{c}, id{i} {};
    char getId();
    char getColour();
    bool hasMoved();
    void setHasMoved();
    virtual bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol) = 0;
};

class Pawn : public Piece
{
public:
    Pawn(char c) : Piece{c, 'P'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class King : public Piece
{
public:
    King(char c) : Piece{c, 'K'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Queen : public Piece
{
public:
    Queen(char c) : Piece{c, 'Q'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Bishop : public Piece
{
public:
    Bishop(char c) : Piece{c, 'B'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Knight : public Piece
{
public:
    Knight(char c) : Piece{c, 'N'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Rook : public Piece
{
public:
    Rook(char c) : Piece{c, 'R'} {};
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};