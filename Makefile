CC=clang 
CFLAGS= -Wall -Werror -Wpedantic -Wextra
LFLAGS=-lm
all: sorting
sorting: sorting.o
	$(CC) -o sorting sorting.o  insert.o  stats.o quick.o heap.o shell.o  $(LFLAGS)
sorting.o: sorting.c set.h stats.h quick.h heap.h shell.h insert.h shell.h
	$(CC) $(CFLAGS) -c sorting.c stats.h set.h  insert.c insert.h  stats.c quick.c quick.h heap.c heap.h shell.h shell.c
clean:
	rm -f sorting.o insert.o stats.o quick.o heap.o shell.o sorting heap.h.gch sorting.h.gch quick.h.gch shell.h.gch insert.h.gch set.h.gch stats.h.gch
format:
	clang-format -i -style=file *.[ch]

