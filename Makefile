all: executable
	./bin/main

executable: design functions main 
	gcc obj/functions.o obj/design.o obj/main.o -Wall -o bin/main

design: src/design.cpp
	gcc src/design.cpp -c -o obj/design.o -Wall

main: src/main.cpp
	gcc src/main.cpp -c -o obj/main.o -Wall

functions: src/functions.cpp
	gcc src/functions.cpp -c -o obj/functions.o -Wall

clean:
	rm -rf obj/*.o
	rm -rf bin/main