#include "../include/board.h"
#include <ctime>
#include <iostream>
// This include allows windows to print the correct character 
#ifdef _WIN32
#include <windows.h>
#endif
#define defaultRows 15
#define defaultCols 17

board::board() {
    gameBoard = new std::vector<std::vector<int> >; // 0 is blank space, 1 is worm, and 2 is an apple
    rows = defaultRows;
    cols = defaultCols;
    // Add all the row vectors 
    for (int i = 0; i < defaultRows; i++) {
        std::vector<int> temp;
        for (int j = 0; j < defaultCols; j++) {
            temp.push_back(0);
        }
        gameBoard->push_back(temp);
    }
    // Set up snake on board and first apple
    for (int k = 4; k >= 1; k--) {
        gameBoard->at(defaultRows/2).at(k) = 1;
    }
    gameBoard->at(defaultRows/2).at(defaultCols-5) = 2;
    // Called to make sure random seed used in functions is different for every run through of the program
    srand(time(0));
}
board::board(int row_u, int col_u, int apples) {
    gameBoard = new std::vector<std::vector<int> >; // 0 is blank space, 1 is worm, and 2 is an apple
    rows = row_u;
    cols = col_u;
    // Add all the row vectors 
    for (int i = 0; i < row_u; i++) {
        std::vector<int> temp;
        for (int j = 0; j < col_u; j++) {
            temp.push_back(0);
        }
        gameBoard->push_back(temp);
    }
    // Set up snake on board and first apple
    for (int k = 4; k >= 1; k--) {
        gameBoard->at(row_u/2).at(k) = 1;
    }
    gameBoard->at(row_u/2).at(col_u - 4) = 2;
    // Called to make sure random seed used in functions is different for every run through of the program
    srand(time(0));
    
    // Add rest of apples in random spots 
    for (int a = 1; a < apples; a++) {
        setApple();
    }
}
board::~board() {
    delete gameBoard;
}


void board::setApple() {
    while(true) {
        int randRow = rand() % (rows);
        int randCol = rand() % (cols);
        if (gameBoard->at(randRow).at(randCol) == 0) {
            gameBoard->at(randRow).at(randCol) = 2;
            return;
        }
    }
}
// Sets a new brick in a random location that isn't in the immediate way of snake
void board::setBrick(int snakeRow, int snakeCol) {
    while(true) {
        int randRow = rand() % (rows);
        int randCol = rand() % (cols);
        // Messy code but checks to make sure it won't spawn brick in immediate location of snake
        if ((randRow == snakeRow && randCol == snakeCol -1) || (randRow == snakeRow && randCol == snakeCol + 1) || (randRow == snakeRow - 1 && randCol == snakeCol) || (randRow == snakeRow + 1 && randCol == snakeCol)) {
            continue;
        }
        if (gameBoard->at(randRow).at(randCol) == 0) {
            gameBoard->at(randRow).at(randCol) = 3;
            return;
        }
    }
}

void board::printBoard() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    for (int i = -1; i < rows + 1; i++) {
        for (int j = -1; j < cols+1; j++) {
            if (i ==rows) {
                // Windows doesn't like this character for some reason, so have to do extra stuff to print correctly
                std::cout << u8"‾";
            }
            else if (i==-1) {
                std::cout << "_";
            }
            else if (j == -1 || j == cols) {
                std::cout << "|";
            }
            else {
                std::cout << printingMap[gameBoard->at(i)[j]];
            }
        }
        std::cout << "\n";
    }
}