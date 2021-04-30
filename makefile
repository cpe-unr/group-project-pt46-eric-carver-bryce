audioprocessor: main.cpp wav.o directory.o 16bitstereo.o 8bitstereo.o Echo.o Normalization.o NoiseGate.o Processor.h
	g++ -std=c++11 main.cpp Wav.o directory.o 16bitstereo.o 8bitstereo.o Echo.o Normalization.o NoiseGate.o -o audioprocessor

wav.o: Wav.cpp Wav.h 16bitstereo.cpp 16bitstereo.h 8bitstereo.cpp 8bitstereo.h
	g++ -c -std=c++11 Wav.cpp 16bitstereo.cpp 8bitstereo.cpp

directory.o: directory.cpp directory.h
	g++ -c -std=c++11 directory.cpp

16bitstereo.o: 16bitstereo.cpp 16bitstereo.h
	g++ -c -std=c++11 16bitstereo.cpp

8bitstereo.o: 8bitstereo.cpp 8bitstereo.h
	g++ -c -std=c++11 8bitstereo.cpp
	
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
	
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp
	
NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++11 NoiseGate.cpp

clean:
	rm *.o audioprocessor
