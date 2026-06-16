#include <vector>

class board {
    private:
        int rows;
        int cols;
        std::vector<std::vector<int> > * gameBoard;
    public:
        board();
        board(int row_u, int col_u);
        ~board();
        int getRows() {return rows;}
        int getCols() {return cols;}
        void setApple();
        void findApple(int & appleRow, int & appleCol);
        void makeMove();
        void isGameOver();

};

