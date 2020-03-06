# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc

# Specify flags
CFLAGS=-Wall -g
 
.PHONY : test rpn
test : test_pila
 
### test_pila MAIN
# Link the object files into a binary
test_pila : test_pila.o pila.o
	$(LINK) $(CFLAGS) -o bin/test_pila obj/test_pila.o obj/pila.o
 
# Compile the source files into object files
test_pila.o : src/test_pila.c
	$(CC) $(CFLAGS) -I include -c src/test_pila.c -o obj/test_pila.o


### rpn MAIN
rpn : rpn.o pila.o
	$(LINK) $(CFLAGS) -o bin/rpn obj/rpn.o obj/pila.o

# Compile the source files into object files
rpn.o : src/rpn.c
	$(CC) $(CFLAGS) -I include -c src/rpn.c -o obj/rpn.o
 

# pila code
pila.o : src/pila.c
	$(CC) $(CFLAGS) -I include -c src/pila.c -o obj/pila.o

# Run
.PHONY : run_test run_rpn
run_test: test_pila
	./bin/test_pila

run_rpn: rpn
	./bin/rpn

# Clean target
.PHONY : clean
clean :
	rm obj/* bin/* 