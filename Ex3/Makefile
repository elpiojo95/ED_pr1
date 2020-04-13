# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc

# Specify flags
CFLAGS=-Wall -g
 
.PHONY : test rpn
test : test_llista
 
### test_llista MAIN
# Link the object files into a binary
test_llista : test_llista.o llista.o random.o
	$(LINK) $(CFLAGS) -o bin/test_llista obj/test_llista.o obj/llista.o obj/random.o -lm
 
# Compile the source files into object files
test_llista.o : src/test_llista.c
	$(CC) $(CFLAGS) -I include -c src/test_llista.c -o obj/test_llista.o

# llista code
llista.o : src/llista.c
	$(CC) $(CFLAGS) -I include -c src/llista.c -o obj/llista.o

# random
random.o : src/random.c
	$(CC) $(CFLAGS) -I include -c src/random.c -o obj/random.o

# Run
.PHONY : run_test run_triangulo
run_test: test_llista
	./bin/test_llista

# Clean target
.PHONY : clean
clean :
	rm obj/* bin/* 