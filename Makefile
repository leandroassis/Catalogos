SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -std=c++11

all: catalogo

%.o: %.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

catalogo: $(OBJ)
	g++ -o $@ $^

clean:
	rm -rf src/*.o ./catalogo