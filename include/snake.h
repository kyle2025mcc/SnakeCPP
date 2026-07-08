#include <deque>
#include "board.h"
// Struct is used to repersent one cell of the snake on the board 
struct snakePosition {
    int row;
    int col;
    snakePosition(int row_u, int col_u) {
        row = row_u;
        col = col_u;
    }
};
// Used as way to see the current direction as a snake.
// Up and down are even while left and right are odd which allows comparisons to be easy
// Also allows for easy math to be made to index on the board
enum snakeDirection{
    up,
    left,
    down,
    right
};


// SnakeQueue repersents each part of the snake on the board and allows it to be easy to get rid of the tail parts 
class snake {
    private:
        int length;
        snakeDirection curDirection;
        std::deque<snakePosition> snakeQueue; // Head of snake is at the head of the queue
    public:
        snake();
        snake(int row_u);
        int getLength() {return length;}
        snakeDirection getDirection() {return curDirection;}
        void setDirection(snakeDirection newDirection) {curDirection = newDirection;}
        std::deque<snakePosition> getQueue() {return snakeQueue;}
        void setLength(int u_length) {length = u_length;}
        int move(board & boardObj); // Most of the game logic is in this function

};