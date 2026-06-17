#include "board.h"
#include "snake.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Create snake and board
    snake snakeObj = snake::snake();
    board boardObj = board::board();
    std::vector<std::vector<int> > * gameBoard = boardObj.getBoard();


}