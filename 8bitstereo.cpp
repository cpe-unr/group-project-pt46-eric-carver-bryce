#include "8bitstereo.h"
#include <iostream>
#include <cstring>
#include <fstream>

void EightBitStereo::makeStereoBuffer(const Wav& wav){
	int i = 0;
	unsigned char *buffer = wav.getBuffer();
	rightBuffer = new unsigned char[(wav.getBufferSize())/2];
	leftBuffer = new unsigned char[(wav.getBufferSize())/2];
	
	for(int j = 0; j < wav.getBufferSize(); j += 2){
		//std::cout << "j" << j << std::endl;
		//std::cout << "buffer" << buffer[j] << std::endl;
		//std::cout << "buffer" << buffer[j+1] << std::endl;
		leftBuffer[i] = buffer[j];
		//std::cout << "left" << leftShortBuffer[i] << std::endl;
		rightBuffer[i] = buffer[j + 1];
		//std::cout << "right" << rightShortBuffer[i] << std::endl;
		//std::cout << "i" << i << std::endl;
		i++;
	}
}	

void EightBitStereo::writeFile(const std::string &outFileName){
	wav_header waveHeader = Wav::getWaveHeader();

	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)combinedBuffer, waveHeader.data_bytes);
	if (metadataHeader.metadataSize > 0){
		outFile.write((char const*)&metadataHeader,sizeof(MetadataHeader));
		for(Metadata storedMetadata : metadataVector){
			outFile.write((char*)&storedMetadata, 8);
			outFile.write((char*)(storedMetadata.metadata.data()), storedMetadata.metadata.length());
		}
	}
	outFile.close();
}

EightBitStereo::EightBitStereo(const Wav& wav): Wav(wav){
	makeStereoBuffer(wav);
}

unsigned char *EightBitStereo::getLeftBuffer(){
	return leftBuffer;
}
unsigned char *EightBitStereo::getRightBuffer(){
	return rightBuffer;
}

void EightBitStereo::combineBuffers(){
	int j = 0;
	wav_header waveHeader = Wav::getWaveHeader();

	for(int i = 0; i < (waveHeader.data_bytes/2); i++){
		combinedBuffer[j] = leftBuffer[i];
		combinedBuffer[j + 1] = rightBuffer[i];
		j += 2;
	}
}
