demo : demo.o bst-implementation.o item-implementation.o
	gcc demo.o bst-implementation.o item-implementation.o -o demo

demo.o :demo.c ST.h Item.h
	gcc -c demo.c

bst-implementation.o :bst-implementation.c Item.h
	gcc -c bst-implementation.c

item-implementation.o :item-implementation.c Item.h
	gcc -c item-implementation.c
clean:
	rm demo demo.o bst-implementation.o item-implementation.o
