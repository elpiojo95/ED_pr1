# Specify compiler
CC=gcc
 
# Specify linker
LINK=gcc

# Specify flags
CFLAGS=-Wall -g
 
.PHONY : test rpn
test : test_cua
 
### test_cua MAIN
# Link the object files into a binary
test_cua : test_cua.o cua.o
	$(LINK) $(CFLAGS) -o bin/test_cua obj/test_cua.o obj/cua.o
 
# Compile the source files into object files
test_cua.o : src/test_cua.c
	$(CC) $(CFLAGS) -I include -c src/test_cua.c -o obj/test_cua.o


### rpn MAIN
triangulo : triangulo.o cua.o
	$(LINK) $(CFLAGS) -o bin/triangulo obj/triangulo.o obj/cua.o

# Compile the source files into object files
triangulo.o : src/trianglePascal.c
	$(CC) $(CFLAGS) -I include -c src/trianglePascal.c -o obj/triangulo.o
 

# cua code
cua.o : src/cua.c
	$(CC) $(CFLAGS) -I include -c src/cua.c -o obj/cua.o

# Run
.PHONY : run_test run_triangulo
run_test: test_cua
	./bin/test_cua

run_triangulo: triangulo
	./bin/triangulo

# Clean target
.PHONY : clean
clean :
	rm obj/* bin/* 