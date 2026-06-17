#include <board.h>
#include <ctime>
#define defaultRows 14
#define defaultCols 16

board::board() {
    gameBoard = new std::vector<std::vector<int> >; // 0 is blank space, 1 is worm, and 2 is an apple
    rows = defaultRows;
    cols = defaultCols;
    // Add all the row vectors 
    for (int i = 0; i <= defaultRows; i++) {
        std::vector<int> temp;
        for (int j = 0; j <= defaultCols; j++) {
            temp.push_back(0);
        }
        gameBoard->push_back(temp);
    }
    // Set up snake on board and first apple
    for (int k = 4; k >= 1; k--) {
        gameBoard->at(defaultRows/2).at(defaultCols) = 1;
    }
    gameBoard->at(defaultRows/2).at(defaultCols-4) = 2;
    // Called to make sure random seed used in functions is different for every run through of the program
    srand(time(0));
}
board::board(int row_u, int col_u) {
    gameBoard = new std::vector<std::vector<int> >; // 0 is blank space, 1 is worm, and 2 is an apple
    rows = row_u;
    cols = col_u;
    // Add all the row vectors 
    for (int i = 0; i <= row_u; i++) {
        std::vector<int> temp;
        for (int j = 0; j <= col_u; j++) {
            temp.push_back(0);
        }
        gameBoard->push_back(temp);
    }
    // Set up snake on board and first apple
    for (int k = 4; k >= 1; k--) {
        gameBoard->at(row_u/2).at(col_u) = 1;
    }
    gameBoard->at(row_u/2).at(col_u-4) = 2;
}
board::~board() {
    delete gameBoard;
}
// Function to find current apple on the board
// May need to change if adding more than one apple on board
void board::findApple(int& appleRow, int& appleCol) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gameBoard->at(i).at(j) == 2) {
                appleRow = i;
                appleCol = j;
                return;
            }
        }
    }
}

void board::setApple() {
    while(true) {
    int randRow = rand() % (rows + 1);
    int randCol = rand() % (cols+1);
    if (gameBoard->at(randRow).at(randCol) == 0) {
        gameBoard->at(randRow).at(randCol) = 2;
        return;
    }
    }
}

void board::printBoard() {
    
}