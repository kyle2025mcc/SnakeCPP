S = src
INC = include
OBJ = 
TARGET = 
CFLAGS = -Wall
 

# Check if the OS environment variable is set to Windows
ifeq ($(OS), Windows_NT)
    # Windows-specific settings (leave blank if no special flags are needed)
	TARGET += game.exe
	OBJ += buildWindows
	RM = del /Q
else
    # Linux/Mac fallback detection
    UNAME_S := $(shell uname -s)
    # Add your Linux-only flags here safely
    ifeq ($(UNAME_S), Linux)
        CFLAGS += -lncurses
		TARGET += game
		OBJ += buildLinux
    endif
endif

$(TARGET): $(OBJ)/main.o $(OBJ)/board.o $(OBJ)/snake.o
	g++  $(OBJ)/main.o $(OBJ)/board.o $(OBJ)/snake.o -o $(TARGET) $(CFLAGS) 

# Creates main object file
$(OBJ)/main.o: $(S)/main.cpp
	g++ -I$(INC) -c $(S)/main.cpp -o $@
# Creates board object file
$(OBJ)/board.o: $(S)/board.cpp $(INC)/board.h
	g++ -I$(INC) -c $(S)/board.cpp -o $@
# Creates snake object file
$(OBJ)/snake.o: $(S)/snake.cpp $(INC)/snake.h
	g++ -I$(INC) -c $(S)/snake.cpp -o $@

clean:
# Allow it to work on windows
ifeq ($(OS),Windows_NT)
	$(RM) $(OBJ)\*.o $(TARGET)
# Allow it to work on anything else
else
	$(RM) $(OBJ)/*.o $(TARGET)
endif