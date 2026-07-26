#include <vector>
#include <map>



class board {
    private:
        int rows; 
        int cols;
        std::vector<std::vector<int> > * gameBoard; // 0 blank space, 1 is snake, and 2 is apple
        // Use a map to print out correct values later
        std::map<int, char> printingMap = {
            {0, '.'}, // Empty space
            {1, 'O'}, // Snake
            {2, 'a'}, // Apple
            {3, 'x'}  // Brick wall
        };
        int isBrickGame;
    public:
        // Used for the default settings
        board();
        // Used for when settings want to be changed
        board(int row_u, int col_u, int apples);
        ~board();
        int getRows() {return rows;}
        int getCols() {return cols;}
        std::vector<std::vector<int> > * getBoard() {return gameBoard;}
        void setApple();
        void printBoard();
        void setIsBrickGame(int ans) {isBrickGame = ans;};
        void setBrick(int snakeRow, int snakeCol);
        int getIsBrickGame() {return isBrickGame;};

};

