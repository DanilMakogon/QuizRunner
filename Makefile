all: executable
	./bin/main

executable: design functions main 
	g++ obj/functions.o obj/design.o obj/main.o -Wall -o bin/main -lstdc++

design: src/design.cpp
	g++ src/design.cpp -c -o obj/design.o -Wall -lstdc++

main: src/main.cpp
	g++ src/main.cpp -c -o obj/main.o -Wall -lstdc++

functions: src/functions.cpp
	g++ src/functions.cpp -c -o obj/functions.o -Wall -lstdc++

clean:
	rm -rf obj/*.o
	rm -rf bin/main