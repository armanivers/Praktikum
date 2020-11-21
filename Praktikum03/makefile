main: dictionary.o main.c dictionary.h 
	gcc main.c -o main dictionary.o

dictionary.o: dictionary.c
	gcc -c dictionary.c

clean:
	rm main dictionary.o
