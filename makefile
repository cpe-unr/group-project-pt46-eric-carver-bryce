audioprocessor: main.cpp wav.o directory.o
	g++ -std=c++11 main.cpp Wav.o directory.o 16bitstereo.o 8bitstereo.o -o audioprocessor

wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

directory.o: directory.cpp directory.h
	g++ -c -std=c++11 directory.cpp

16bitstereo.o: 16bitstereo.cpp 16bitstereo.h
	g++ -c -std=c++11 16bitstereo.cpp

8bitstereo.o: 8bitstereo.cpp 8bitstereo.h
	g++ -c -std=c++11 8bitstereo.cpp

clean:
	rm *.o audioprocessor
