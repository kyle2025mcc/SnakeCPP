#include <vector>
#include <map>



class board {
    private:
        int rows;  // These two values are 0 indexed 
        int cols;
        std::vector<std::vector<int> > * gameBoard; // 0 blank space, 1 is snake, and 2 is apple
        // Use a map to print out correct values later
        std::map<int, char> printingMap = {
            {0, '.'},
            {1, 'O'},
            {2, 'a'}
        };
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

