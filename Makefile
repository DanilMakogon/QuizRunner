all: executable
	./bin/main

executable: design functions main 
	g++ obj/functions.o obj/design.o obj/main.o -Wall -o bin/main -lstdc++ -lncurses

design: src/design.cpp
	g++ src/design.cpp -c -o obj/design.o -Wall -lstdc++ -lncurses

main: src/main.cpp
	g++ src/main.cpp -c -o obj/main.o -Wall -lstdc++ -lncurses

functions: src/functions.cpp
	g++ src/functions.cpp -c -o obj/functions.o -Wall -lstdc++ -lncurses

clean:
	rm -rf obj/*.o
	rm -rf bin/main