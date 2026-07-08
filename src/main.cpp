#include "../include/snake.h"
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <conio.h> // Only works for windows, but allows input to be read without enter being pressed
#endif
// Next two libraries and the namespace used for sleep functions
#include <chrono>
#include <thread> 
using namespace std::literals::chrono_literals;



int moveInputed = 0;

// Reminder for later all rows and column values are zero indexed 

// Function to clear the input stream. Used to prevent player from getting locked out of inputs 
void clearIn() {
    while(_kbhit()) {
        _getch();
    }
}

// Function checks for input only for windows and returns the correct direction
snakeDirection windowsChecker(snake snakeObj) {
    std::map<char, snakeDirection> directionInput {
        {'w', up},
        {'a', left},
        {'d', right},
        {'s', down}
    };
    if (_kbhit()) {
        char input = _getch();
        if (input == 'a' || input == 'd' || input == 's' || input == 'w' ) {
            snakeDirection dir = directionInput[input];
            // Direction inputed isn't valid for the current direction
            if (dir % 2 == snakeObj.getDirection() % 2) {
                clearIn();
                return snakeObj.getDirection();
            }
            clearIn();
            return dir;
        }
        // Valid character isn't entered, so keep going
        else {
            clearIn();
            return snakeObj.getDirection();
        }
        
    }
    return snakeObj.getDirection();
}



int main() {
    // Create snake and board
    snake snakeObj = snake();
    board boardObj = board();
    // Variable to end the loop and game
    int continueGame = 1;
    // Variable to pass to the move function, contains the direction to move
    snakeDirection curDirection = right;

    while (continueGame) {
        boardObj.printBoard();
        std::this_thread::sleep_for(1s);
        snakeObj.setDirection(windowsChecker(snakeObj));
        continueGame = snakeObj.move(boardObj);
    }


}