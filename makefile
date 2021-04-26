audioprocessor: main.cpp wav.o directory.o
	g++ -std=c++11 main.cpp Wav.o directory.o -o audioprocessor

wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

directory.o: directory.cpp directory.h
	g++ -c -std=c++11 directory.cpp


clean:
	rm *.o audioprocessor
