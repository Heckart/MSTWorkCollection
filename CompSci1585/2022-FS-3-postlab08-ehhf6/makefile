CFLAGS=-Wall -Werror

test: testsuite
	@./testsuite

coverage: CFLAGS=-Wall -Werror -fprofile-arcs -ftest-coverage
coverage: clean testsuite
	@./testsuite
	gcov -r test_main.cpp

main: list.o main.o
	g++ ${CFLAGS} $^ -o main

testsuite: test_main.o
	g++ ${CFLAGS} $^ -o testsuite

main.o: main.cpp list.h list.hpp
	g++ ${CFLAGS} -c main.cpp

list.o: list.h list.hpp
	g++ ${CFLAGS} -c list.hpp

test_main.o: test_main.cpp
	g++ ${CFLAGS} -c test_main.cpp

clean:
	-@rm -f main testsuite
	-@rm -f *.o
	-@rm -f *.gcov *.gcno *.gcda
