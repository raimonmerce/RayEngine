CC = g++
CFLAGS = -Iinclude -mconsole -lopengl32 -lglu32 -lfreeglut

# Recursive wildcard function: Searches a directory and its subdirectories for a given pattern.
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# Use the function to find all .cpp files under src/ and include main.cpp
SRC = main.cpp $(call rwildcard,src/,*.cpp)
OBJ = $(SRC:.cpp=.o)

# Default target: build the executable and then run it.
all: game.exe run

game.exe: $(OBJ)
	$(CC) $(OBJ) -o game.exe $(CFLAGS)

# Phony target to run the executable
run: game.exe
	./game.exe

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) game.exe

.PHONY: all run clean
