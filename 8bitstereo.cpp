#include "8bitstereo.h"
#include <iostream>

void EightBitStereo::makeStereoBuffer(Wav* wav){
	int i = 0;
	unsigned char *buffer = wav->getBuffer();
	rightBuffer = new unsigned char[(wav->getBufferSize())/2];
	leftBuffer = new unsigned char[(wav->getBufferSize())/2];
	std::cout << wav->getBufferSize() << std::endl;
	
	for(int j = 0; j < (wav->getBufferSize() - 2); j += 2){
		//std::cout << "short" << shortBuffer[i] << std::endl;
		leftBuffer[i] = buffer[j];
		//std::cout << "left" << leftShortBuffer[i] << std::endl;
		rightBuffer[i] = buffer[j + 1];
		//std::cout << "right" << rightShortBuffer[i] << std::endl;
		//std::cout << "j" << j << std::endl;
		//std::cout << "i" << i << std::endl;
		i++;
	}
}	

EightBitStereo::EightBitStereo(Wav* wav){
	//makeStereoBuffer(wav);
}

unsigned char *EightBitStereo::getLeftBuffer(){
	return leftBuffer;
}
unsigned char *EightBitStereo::getRightBuffer(){
	return rightBuffer;
}
