CC = g++	#C++ compiler
CFLAGS = -Wall -Wextra -std=c++11 -g #Compiler flags
SRC = main.cpp #Source files
OBJ = $(SRC:.cpp=.o) #Object files
EXEC = aizo #Executable name

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)