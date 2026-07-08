#include "../include/snake.h"
#define defaultLength 4

// Head starts at row 7 and col 4 with length 4
snake::snake() {
    length = defaultLength;
    curDirection = right; // Default positition goes right
    for (int i = 4; i >= 1; i--) {
        snakeQueue.push_back(snakePosition(7, i));
    }
}
// If amount of rows want to be changed
snake::snake(int row_u) {
    length = defaultLength;
    curDirection = right; // Default positition goes right
    for (int i = 4; i >= 1; i--) {
        snakeQueue.push_back(snakePosition(row_u / 2, i));
    }
}
// Function returns 0 if game is over and 1 otherwise
int snake::move(board & boardObj) {

    // Get current current board
    std::vector<std::vector<int> > * curBoard = boardObj.getBoard();
    // Create the new head
    int curHeadRow = snakeQueue.front().row;
    int curHeadCol = snakeQueue.front().col;
    // Check if movement if vertical
    if (curDirection % 2 == 0) {
        snakeQueue.push_front(snakePosition(curHeadRow + (curDirection-1), curHeadCol));
        curHeadRow = curHeadRow + (curDirection-1);
    }
    // Else movement is horizontal
    else {
        snakeQueue.push_front(snakePosition(curHeadRow, curHeadCol + (curDirection-2)));
        curHeadCol = curHeadCol + (curDirection-2);
    }

    // Check if the border is hit
    if (curHeadRow == -1 || curHeadRow == boardObj.getRows() + 1 || curHeadCol == -1 || curHeadCol == boardObj.getCols() + 1) {
        return 0;
    }
    // Check if new head hits a part of the snake
    if (curBoard->at(curHeadRow).at(curHeadCol) == 1) {
        return 0;
    }
    // See if apple is hit 
    int appleRow, appleCol;
    boardObj.findApple(appleRow, appleCol);
    if (curHeadRow == appleRow && curHeadCol == appleCol) {
        length++;
        // Have to update board now or else there is a case where apple fills in where head is
        curBoard->at(curHeadRow).at(curHeadCol) = 1;
        boardObj.setApple(); // Create a new apple
    }
    // If apple isn't hit delete the tail of the snake
    else {
        int tailRow = snakeQueue.back().row;
        int tailCol = snakeQueue.back().col;
        snakeQueue.pop_back();
        curBoard->at(tailRow).at(tailCol) = 0;
        curBoard->at(curHeadRow).at(curHeadCol) = 1;
    }
    return 1;
}
