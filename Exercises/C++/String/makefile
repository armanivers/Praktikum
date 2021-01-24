main: string.o main.cpp string.h 
	g++ main.cpp -o main string.o

string.o: string.cpp
	g++ -c string.cpp

clean:
	rm main string.o
