#pragma once

#include <string>

class Piece
{
protected:
    char id, colour;
    bool status{false}; // if piece has moved or not
public:
    Piece(char c, char i) : colour{c}, id{i} {};
    virtual ~Piece() = default;
    virtual std::string getSymbol() = 0;
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
    std::string getSymbol() final { return (colour == 'B') ? "♙" : "♟"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class King : public Piece
{
public:
    King(char c) : Piece{c, 'K'} {};
    std::string getSymbol() final { return (colour == 'B') ? "♔" : "♚"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Queen : public Piece
{
public:
    Queen(char c) : Piece{c, 'Q'} {};
    std::string getSymbol() final { return (colour == 'B') ? "♕" : "♛"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Bishop : public Piece
{
public:
    Bishop(char c) : Piece{c, 'B'} {};
    std::string getSymbol() final { return (colour == 'B') ? "♗" : "♝"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Knight : public Piece
{
public:
    Knight(char c) : Piece{c, 'N'} {};
    std::string getSymbol() final { return (colour == 'B') ? "♘" : "♞"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class Rook : public Piece
{
public:
    Rook(char c) : Piece{c, 'R'} {};
    std::string getSymbol() final { return (colour == 'B') ? "♖" : "♜"; }
    bool isMoveAllowed(Piece* temp[8][8], int irow, int icol, int frow, int fcol);
};

class PieceFactory
{
public:
    static Piece* createPiece(char type, char color)
    {
        switch (type)
        {
            case 'P':
                return new Pawn(color);
            case 'K':
                return new King(color);
            case 'Q':
                return new Queen(color);
            case 'B':
                return new Bishop(color);
            case 'N':
                return new Knight(color);
            case 'R':
                return new Rook(color);
            default:
                return nullptr;
        }
    }
};