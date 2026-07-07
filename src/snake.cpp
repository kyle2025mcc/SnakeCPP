#include "../include/snake.h"
#define defaultLength 4

// Head starts at row 7 and col 4 with length 4
snake::snake() {
    length = defaultLength;
    curDirection = right; // Default positition goes right
    snake::snakeQueue = new std::deque<snakePosition>;
    for (int i = 4; i >= 1; i--) {
        snakeQueue->push_back(snakePosition(7, i));
    }
}
// If amount of rows want to be changed
snake::snake(int row_u) {
    length = defaultLength;
    curDirection = right; // Default positition goes right
    snake::snakeQueue = new std::deque<snakePosition>;
    for (int i = 4; i >= 1; i--) {
        snakeQueue->push_back(snakePosition(row_u / 2, i));
    }
}
snake::~snake() {
    delete snakeQueue;
}
