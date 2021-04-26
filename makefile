audioprocessor: main.cpp wav.o
	g++ -std=c++11 main.cpp Wav.o -o audioprocessor

wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

clean:
	rm *.o audioprocessor
