main: uppercaseWriter.o queue.o main.c uppercaseWriter.h queue.h
	gcc main.c -o main uppercaseWriter.o queue.o

uppercaseWriter.o: uppercaseWriter.c
	gcc -c uppercaseWriter.c

queue.o: queue.c
	gcc -c queue.c

clean:
	rm main uppercaseWriter.o queue.o
