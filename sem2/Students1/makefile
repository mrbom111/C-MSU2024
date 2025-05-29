all: main.o search.o
	gcc main.o search.o && del *.o
main.o: main.c
	gcc -c main.c
search.o: search.c
	gcc -c search.c