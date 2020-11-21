main: ascii.o multiply.o main.c ascii.h multiply.h
	gcc main.c -o main ascii.o multiply.o

ascii.o: ascii.c
	gcc -c ascii.c

multiply.o: multiply.c
	gcc -c multiply.c

clean:
	rm main ascii.o
