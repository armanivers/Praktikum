main: medium.o audio.o bild.o main.cpp medium.h audio.h bild.h
	g++ main.cpp -o main medium.o audio.o bild.o

medium.o: medium.cpp
	g++ -c medium.cpp

audio.o: audio.cpp
	g++ -c audio.cpp

bild.o: bild.cpp
	g++ -c bild.cpp

clean:
	rm main medium.o audio.o bild.o
