
all:  buildlib buildmain run
builddebug: buildlib buildmain
	
buildlib:
	g++  -c students.cpp -o lib/students.o
	g++  -shared -o students.dll lib/students.o
buildmain:
	g++ -g main.cpp -L. students.dll -o main
run:
	./main.exe
