CPPFLAGS = -c -Iinc -O3

__start__: projekt_2
		./projekt_2

./projekt_2: obj/main.o 
		g++ -Wall -pedantic -o projekt_2 obj/main.o

obj/main.o: src/main.cpp
		g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/data_functions.o: src/data_functions.cpp inc/data_structure.hh
		g++ ${CPPFLAGS} -o obj/data_functions.o src/data_functions.cpp

obj/sorting_functions.o: src/sorting_functions.cpp inc/data_structure.hh inc/vector.hh
		g++ ${CPPFLAGS} -o obj/sorting_functions.o sorting_functions.cpp

clean:
		rm -f obj/*.o projekt_2