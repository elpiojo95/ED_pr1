# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc

# Specify flags
CFLAGS=-Wall -g
 
.PHONY : test
test : test_pila
 
# Link the object files into a binary
test_pila : test_pila.o pila.o
	$(LINK) $(CFLAGS) -o bin/test_pila obj/test_pila.o obj/pila.o
 
# Compile the source files into object files
test_pila.o : src/test_pila.c
	$(CC) $(CFLAGS) -I include -c src/test_pila.c -o obj/test_pila.o
 
pila.o : src/pila.c
	$(CC) $(CFLAGS) -I include -c src/pila.c -o obj/pila.o

# Run
run_test:
	./bin/test_pila

# Clean target
.PHONY : clean
clean :
	rm obj/* bin/* 