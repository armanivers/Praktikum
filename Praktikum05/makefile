main: countspace.o min.o stringcat.o factorial.o main.c countspace.h min.h stringcat.h factorial.h 
	gcc main.c -o main countspace.o min.o stringcat.o factorial.o

countspace.o: countspace.c
	gcc -c countspace.c

min.o: min.c
	gcc -c min.c

stringcat.o: stringcat.c
	gcc -c stringcat.c

factorial.o: factorial.c
	gcc -c factorial.c

clean:
	rm main countspace.o min.o stringcat.o factorial.o
