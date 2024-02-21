CC=gcc
CFLAGS=-Wall -Wextra -Werror
CLANG=clang-format -i
CPP=cppcheck --enable=all --suppress=missingIncludeSystem
LDFLAGS=
SOURCES=operations.c stack.o graph.c transform.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/graph
MAIN=../src/


all: stack.o stack.a
	$(CC) $(CFLAGS) $(SOURCES) -L $(MAIN) $(MAIN)stack.a -o $(EXECUTABLE)

stack.a: stack.o
	ar rcs stack.a stack.o

clean:
	rm -rf *.o *.a