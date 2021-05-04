
audioprocessor: main.cpp Wav.o directory.o 16bitstereo.o 8bitstereo.o 16bitmono.o 8bitmono.o Echo.o Normalization.o NoiseGate.o ProcessorChoice.o CSVmenu.o Processor.h
	g++ -std=c++11 main.cpp Wav.o directory.o 16bitstereo.o 8bitstereo.o 16bitmono.o 8bitmono.o Echo.o Normalization.o NoiseGate.o ProcessorChoice.o CSVmenu.o -o audioprocessor

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

directory.o: directory.cpp directory.h
	g++ -c -std=c++11 directory.cpp

16bitstereo.o: 16bitstereo.cpp 16bitstereo.h
	g++ -c -std=c++11 16bitstereo.cpp

8bitstereo.o: 8bitstereo.cpp 8bitstereo.h
	g++ -c -std=c++11 8bitstereo.cpp

16bitmono.o: 16bitmono.cpp 16bitmono.h
	g++ -c -std=c++11 16bitmono.cpp

8bitmono.o: 8bitmono.cpp 8bitmono.h
	g++ -c -std=c++11 8bitmono.cpp
	
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
	
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp
	
NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++11 NoiseGate.cpp
	
Gui.o: Gui.cpp Gui.h
	g++ -c -std=c++11 Gui.cpp
	
ProcessorChoice.o: ProcessorChoice.cpp ProcessorChoice.h
	g++ -c -std=c++11 ProcessorChoice.cpp

CSVmenu.o: CSVmenu.cpp CSVmenu.h
	g++ -c -std=c++11 CSVmenu.cpp

clean:
	rm *.o audioprocessor
