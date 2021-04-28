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

/*wav_header Wav::getWaveHeader() {
	return waveHeader;
}*/

int Wav::getChannels() const{
	return waveHeader.num_channels;
}
int Wav::getBitDepth() const{
	return waveHeader.bit_depth;
}

Wav *Wav::cast(Wav* wav) {
	
	if(wav->getChannels() == 2){
		if(wav->getBitDepth() == 8){
			//Wav * newWave = new EightBitStereo(wav);
			//return newWave;
		}

		else if(wav->getBitDepth() == 16){
			//Wav * newWave = new SixteenBitStereo(wav);
			//return newWave;
		}
	}

	else if(wav->getChannels() == 1){
		if(wav->getBitDepth() == 8){
		
		}

		else if(wav->getBitDepth() == 16){
		
		}
	}
}
