demo : demo.o bst-implementation.o
	gcc demo.o bst-implementation.o -o demo

demo.o :demo.c ST.h 
	gcc -c demo.c 

bst-implementation.o :bst-implementation.c 
	gcc -c bst-implementation.c

clean:
	rm demo demo.o bst-implementation.o
