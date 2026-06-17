#include <vector>

class board {
    private:
        int rows;
        int cols;
        std::vector<std::vector<int> > * gameBoard; // 0 blank space, 1 is snake, and 2 is apple
    public:
        board();
        board(int row_u, int col_u);
        ~board();
        int getRows() {return rows;}
        int getCols() {return cols;}
        std::vector<std::vector<int> > * getBoard() {return gameBoard;}
        void setApple();
        void findApple(int & appleRow, int & appleCol);
        void printBoard();
        void makeMove();
        void isGameOver();

};

