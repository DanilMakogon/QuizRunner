all: main

main: design.o main.o functions.o
	gcc obj/functions.o obj/design.o obj/main.o -Wall -o bin/main

functions.o: src/functions.cpp
	gcc src/functions.cpp -c -o obj/functions.o -Wall

design.o: src/design.cpp
	gcc src/design.cpp -c -o obj/design.o -Wall

main.o: src/main.cpp
	gcc src/main.cpp -c -o obj/main.o -Wall

clean:
	rm -rf obj/*.o
	rm -rf bin/main