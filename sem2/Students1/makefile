all: main.o func.o file_gen.o sort.o
	gcc main.o func.o file_gen.o sort.o && del *.o
main.o: main.c
	gcc -c main.c
func.o: func.c
	gcc -c func.c
file_gen.o: file_gen.c
	gcc -c file_gen.c
sort.o: sort.c
	gcc -c sort.c