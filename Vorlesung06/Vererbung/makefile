main: angestellter.o manager.o main.cpp angestellter.h manager.h
	g++ main.cpp -o main angestellter.o manager.o

angestellter.o: angestellter.cpp
	g++ -c angestellter.cpp

manager.o: manager.cpp
	g++ -c manager.cpp

clean:
	rm main angestellter.o manager.o
