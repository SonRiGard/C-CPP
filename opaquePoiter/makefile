build:
	gcc -c main.c -o main.o
	gcc -c opaque.c -o opaque.o
	ar rcs opaque.a opaque.o
	gcc -g main.o -L. opaque.a -o main1.exe

run:
	./main1.exe