CFLAGS=-lstdc++ -lncursesw -g -Wall

all: executable
	./bin/main

executable: design functions main 
	g++ obj/functions.o obj/design.o obj/main.o -o bin/main $(CFLAGS)

design: src/design.cpp
	g++ src/design.cpp -c -o obj/design.o $(CFLAGS)

main: src/main.cpp
	g++ src/main.cpp -c -o obj/main.o $(CFLAGS)

functions: src/functions.cpp
	g++ src/functions.cpp -c -o obj/functions.o $(CFLAGS)

clean:
	rm -rf obj/*.o
	rm -rf bin/main