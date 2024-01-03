main : main.o Implementation.o 
	gcc main.o Implementation.o -o main

main.o :main.c Interface.h 
	gcc -c main.c

Implementation.o :Implementation.c Interface.h
	gcc -c Implementation.c

clean:
	rm  main main.o Implementation.o 
