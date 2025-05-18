all: string.o search.o
	gcc string.o search.o && del *.o
string.o: string.c
	gcc -c string.c
search.o: search.c
	gcc -c search.c