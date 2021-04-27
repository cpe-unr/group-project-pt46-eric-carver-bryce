#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"
#include "8bitstereo.h"
#include "16bitstereo.h"

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
        file.close();
    }
}

unsigned char *Wav::getBuffer() const{
    return buffer;
}

short *Wav::getShortBuffer() const{
    short* shortBuffer = reinterpret_cast<short*>(buffer);
    return shortBuffer;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}

wav_header Wav::getWaveHeader() const{
	return waveHeader;
}

void Wav::cast(Wav* wav) {
	wav_header header = wav->getWaveHeader();
	if(header.num_channels == 2){
		if(header.bit_depth == 8){
			dynamic_cast<EightBitStereo*>(wav);
		}

		else if(header.bit_depth == 16){
			dynamic_cast<SixteenBitStereo*>(wav);
		}
	}

	else if(header.num_channels == 1){
		if(header.bit_depth == 8){
		//	dynamic_cast<EightBitMono*>(wav);
		}

		else if(header.bit_depth == 16){
		//	dynamic_cast<SixteenBitMono*>(wav);
		}
	}
}
