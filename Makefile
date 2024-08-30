a.out: obj/main.o obj/array.o
	g++ main.o array.o

obj/main.o: main.cpp array.h
	g++ -c main.cpp -o obj/main.o

obj/array.o: array.cpp array.h
	g++ -c array.cpp -o obj/array.o
