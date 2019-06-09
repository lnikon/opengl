SRC = $(wildcard *.cpp)
INC = -I./../global_glad/include -I/usr/include/GLFW
OBJ = $(SRC:.cpp=.o)
CC = g++
LDFALGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -g -O0 -fsanitize=address -Wall -std=c++17

main: $(SRC)
	$(CC) -o $@ $^ $(LDFALGS) $(INC) 

.PHONY: clean

clean:
	rm -f main
