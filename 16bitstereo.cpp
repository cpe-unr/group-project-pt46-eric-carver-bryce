#include "16bitstereo.h"
#include <iostream>
#include <fstream>

void SixteenBitStereo::makeStereoBuffer(const Wav& wav){
	int i = 0;
	shortBuffer = wav.getShortBuffer();
	rightShortBuffer = new short[(wav.getBufferSize())/2];
	leftShortBuffer = new short[(wav.getBufferSize())/2];
	
	for(int j = 0; j < (wav.getBufferSize() - 2); j += 2){
		//std::cout << "j" << j << std::endl;
		//std::cout << "short" << shortBuffer[j] << std::endl;
		//std::cout << "short" << shortBuffer[j+1] << std::endl;
		leftShortBuffer[i] = shortBuffer[j];
		//std::cout << "left" << leftShortBuffer[i] << std::endl;
		rightShortBuffer[i] = shortBuffer[j + 1];
		//std::cout << "right" << rightShortBuffer[i] << std::endl;
		//std::cout << "i" << i << std::endl;
		i++;
	}
}	

SixteenBitStereo::SixteenBitStereo(const Wav& wav): Wav(wav) {
	makeStereoBuffer(wav);
}

SixteenBitStereo::SixteenBitStereo(const SixteenBitStereo& rhs): Wav(rhs) {}

void SixteenBitStereo::writeFile(const std::string &outFileName){
	wav_header waveHeader = Wav::getWaveHeader();

	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char const*)shortBuffer, waveHeader.data_bytes);
	if (metadataHeader.metadataSize > 0){
		outFile.write((char const*)&metadataHeader,sizeof(MetadataHeader));
		for(Metadata storedMetadata : metadataVector){
			outFile.write((char*)&storedMetadata, 8);
			outFile.write((char*)(storedMetadata.metadata.data()), storedMetadata.metadata.length());
		}
	}
	outFile.close();
}

short *SixteenBitStereo::getBuffer() const{
    return shortBuffer;
}

short *SixteenBitStereo::getLeftBuffer(){
	return leftShortBuffer;
}
short *SixteenBitStereo::getRightBuffer(){
	return rightShortBuffer;
}

void SixteenBitStereo::combineBuffers(){
	int j = 0;
	wav_header waveHeader = Wav::getWaveHeader();

	for(int i = 0; i < (waveHeader.data_bytes/2); i++){
		shortBuffer[j] = leftShortBuffer[i];
		shortBuffer[j + 1] = rightShortBuffer[i];
		j += 2;
	}
}
