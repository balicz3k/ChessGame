cmake_minimum_required(VERSION 3.5)

Project(ChessGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ToChess 
               main.cpp
               Board.cpp
               Pieces.cpp
               Game.cpp)