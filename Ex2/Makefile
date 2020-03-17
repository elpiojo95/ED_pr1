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
rpn : rpn.o cua.o
	$(LINK) $(CFLAGS) -o bin/rpn obj/rpn.o obj/cua.o

# Compile the source files into object files
rpn.o : src/rpn.c
	$(CC) $(CFLAGS) -I include -c src/rpn.c -o obj/rpn.o
 

# cua code
cua.o : src/cua.c
	$(CC) $(CFLAGS) -I include -c src/cua.c -o obj/cua.o

# Run
.PHONY : run_test run_rpn
run_test: test_cua
	./bin/test_cua

run_rpn: rpn
	./bin/rpn

# Clean target
.PHONY : clean
clean :
	rm obj/* bin/* 