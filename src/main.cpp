#include "../include/snake.h"
#include <iostream>
// Utillized for windows input
#ifdef _WIN32
#include <conio.h> // Only works for windows, but allows input to be read without enter being pressed
#endif
#define isWindows _WIN32
// Utilized for linux inputs
#ifdef __linux__
#include <ncurses.h>
#endif
// Next two libraries and the namespace used for sleep functions
#include <chrono>
#include <thread> 
using namespace std::literals::chrono_literals;

#define defaultRows 14
#define defaultCols 16


// Reminder for later all rows and column values are zero indexed 

// Used to check input and get correct direction
std::map<char, snakeDirection> directionInput {
        {'w', up},
        {'a', left},
        {'d', right},
        {'s', down}
    };
    


// Code is defined for windows systems 
#ifdef _WIN32
// Function to clear the input stream. Used to prevent player from getting locked out of inputs 
void clearIn() {
    while(_kbhit()) {
        _getch();
    }
}


// Function checks for input only for windows and returns the correct direction
snakeDirection checker(snake snakeObj) {
    
    if (_kbhit()) {
        char input = _getch();
        if (input == 'a' || input == 'd' || input == 's' || input == 'w' ) {
            snakeDirection dir = directionInput[input];
            // Direction inputed isn't valid for the current direction
            if (dir % 2 == snakeObj.getDirection() % 2) {
                return snakeObj.getDirection();
            }
            return dir;
        }
        // Valid character isn't entered, so keep going
        else {
            return snakeObj.getDirection();
        }
        
    }
    return snakeObj.getDirection();
}
#endif
// Code is defined for linux
#ifdef __linux__
void clearIn() {
    for (int i = 0; i<= 20; i++) {
        getch();
    }
 }

snakeDirection checker(snake snakeObj){
    initscr(); // Intitiate the library 
    cbreak();  // Don't buffer input
    noecho();  // Don't echo input back to terminal
    scrollok(stdscr, TRUE); 
    nodelay(stdscr, TRUE);
    char input = getch();
    if (input == 'w' || input == 's' || input == 'a' || input == 'd') {
        snakeDirection dir = directionInput[input];
        // Direction inputed isn't valid for the current direction
            if (dir % 2 == snakeObj.getDirection() % 2) {
                endwin(); // clean up
                return snakeObj.getDirection();
            }
            // Direction inputed is fine
            endwin(); // clean up
            return dir;
        }
    // Input isn' valid so keep going
    endwin(); // clean up
    return snakeObj.getDirection();
     
    }
#endif


int main() {
    std::cout << "Do you want to play with default settings (1) or change it up (0)? ";
    int isDefault;
    std::cin >> isDefault;
    snake * snakeObj;
    board * boardObj;

    // Create snake and board for default settings
    if (isDefault) {
        snakeObj = new snake();
        boardObj = new board();
    }
    else {
        int rows, cols;
        while(true) {
            std::cout << "Enter the amount of rows for the grid (must be at least 9) or use the default value (enter 0): ";
            std::cin >> rows;
            if (rows == 0) rows = 15;
            else if (rows < 9) {
                std::cout << "Enter a valid amount of rows" << std::endl;
                continue;
            }
            break;
        }
        while(true) {
            std::cout<< "Enter the amount of columns for the grid (must be at least 9) or use the default value(0): ";
            std::cin >> cols;
            if (cols==0) cols = 17;
            else if (cols < 9) {
                std::cout << "Enter a valid amount of columns" << std::endl;
                continue;
            }
            break;
        }
        snakeObj = new snake(rows);
        boardObj = new board(rows, cols);

    }
        
    // These lines will run for all settings 
    // Variable to end the loop and game
    int continueGame = 1;
    // Variable to pass to the move function, contains the direction to move
    snakeDirection curDirection = right;

    while (continueGame) {
        boardObj->printBoard();
        std::this_thread::sleep_for(0.8s);
        snakeObj->setDirection(checker(*snakeObj));
        clearIn();
        continueGame = snakeObj->move(*boardObj);
        #ifdef __linux
            endwin();
        #endif
    }
    delete snakeObj;
    delete boardObj;

}