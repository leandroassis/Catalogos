CPPFLAGS = -Wall -std=c++11 -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

all: catalogo

src/Catalogo.o: src/Catalogo.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/Filme.o: src/Filme.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/main.o: src/main.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

catalogo: src/main.o src/Filme.o src/Catalogo.o
	g++ -o $@ src/*.o

clean:
	rm -rf src/*.o ./catalogo
