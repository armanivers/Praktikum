main: rational.o main.cpp rational.h
	g++ main.cpp -o main rational.o -std=c++11

rational.o: rational.cpp
	g++ -c rational.cpp

clean:
	rm main rational.o
