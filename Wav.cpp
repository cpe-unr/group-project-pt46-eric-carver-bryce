#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"

void Wav::readFile(const std::string &fileName) {
    std::ifstream file;
    file.open(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
        file.close();

	std::cout << 1 << std::endl;
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

wav_header Wav::getWaveHeader() {
	return waveHeader;
}

void Wav::setWaveHeader(wav_header* header) {
	
}

bool Wav::isStereo() {
	if(waveHeader.num_channels == 2){
		return true;
	}

	else if(waveHeader.num_channels == 1){
		return false;
	}
}

bool Wav::is16Bit() {
	if(waveHeader.bit_depth == 16){
		return true;
	}

	else if(waveHeader.bit_depth == 8){
		return false;
	}
}


