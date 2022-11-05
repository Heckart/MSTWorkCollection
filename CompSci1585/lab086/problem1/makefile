funcs: funcs.cpp
	g++  funcs.cpp

main: main.cpp
	g++  main.cpp

triprint: TrianglePrinter.cpp
	g++  TrianglePrinter.cpp

program: funcs.cpp main.cpp TrianglePrinter.cpp
	g++ *.cpp -o program

.PHONY: clean

clean:
	-@rm -f program
	-@rm -f *.0
	-@rm -f *.out
