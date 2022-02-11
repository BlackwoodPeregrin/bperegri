all: test

test: test.o funcs.o
	gcc $^ -o test

test.o: test.c test.h
	gcc -c -o test.o test.c

funcs.o: funcs.c test.h
	gcc -c -o funcs.o funcs.c

clean:
	rm -rf *.o test