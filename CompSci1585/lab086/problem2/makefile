COMPILER = g++
ofiles=$(wildcard *.o)
CFLAGS = -02
DEBUGFLAGS = -g -Wall -Wextra

program: ofiles
	${COMPILER} ${CFLAGS} ofiles -o program

main.o: main.cpp funcs.h TrianglePrinter.h
	${COMPILER} ${CLFAGS} -c main.cpp

funcs.o: funcs.cpp funcs.h
	${COMPILER} ${CFLAGS} -c funcs.cpp

TrianglePrinter.o: TrianglePrinter.cpp TrianglePrinter.h
	${COMPILER} ${CLFAGS} -c TrianglePrinter.cpp

.PHONY debug clean
debug: CFLAGS=${DEBUGFLAGS}
debug: program

clean:
	-@ rm -f program *.o
