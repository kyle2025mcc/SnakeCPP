#include "../include/board.h"
#include "../include/snake.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Create snake and board
    snake snakeObj = snake();
    board boardObj = board();
    std::vector<std::vector<int> > * gameBoard = boardObj.getBoard();
    boardObj.printBoard();

}