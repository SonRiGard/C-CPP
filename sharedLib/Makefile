buildlib:
	gcc -c mathlib.c -o lib/mathlib.o
	gcc -shared -o mathlib.dll lib/mathlib.o

linkprogram:
	gcc main.c -L. mathlib.dll -o main

