CC=g++
FLAGS=-std=c++20 -Wall -Werror -Wextra -Wno-unused-variable

all: tests_bin

tests_bin: utils.o tests.o
	$(CC) $(FLAGS) -lgtest_main -lgtest -lpthread -o tests tests.o utils.o

utils.o: utils.cpp utils.hpp
	$(CC) $(FLAGS) -c utils.cpp

tests.o: tests.cpp
	$(CC) $(FLAGS) -lgtest_main -lgtest -lpthread -c tests.cpp

#utils.o: square.o
#	...
test:
	./tests

clean:
	rm -rf *.o tests
