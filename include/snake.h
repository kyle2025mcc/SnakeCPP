#include <deque>

// Struct is used to repersent one cell of the snake on the board 
struct snakePosition {
    int row;
    int col;
    snakePosition(int row_u, int col_u) {
        row = row_u;
        col = col_u;
    }
};

typedef enum snakeDirection{
    up,
    down,
    right,
    left
};


// SnakeQueue repersents each part of the snake on the board and allows it to be easy to get rid of the tail parts 
class snake {
    private:
        int length;
        snakeDirection curDirection;
        std::deque<snakePosition>* snakeQueue; // Head is at the head of the queue
    public:
        snake();
        snake(int row_u);
        ~snake();
        int getLength() {return length;}
        std::deque<snakePosition>* getQueue() {return snakeQueue;}
        void setLength(int u_length) {length = u_length;}
        void move();

};