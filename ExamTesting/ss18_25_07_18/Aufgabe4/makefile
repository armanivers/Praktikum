main: vector.o main.cpp vector.h
	g++ main.cpp -o main vector.o -std=c++11

vector.o: vector.cpp
	g++ -c vector.cpp

clean:
	rm main vector.o
