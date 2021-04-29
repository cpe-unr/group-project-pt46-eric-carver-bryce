#include "16bitstereo.h"
#include <iostream>

void SixteenBitStereo::makeStereoBuffer(Wav* wav){
	int i = 0;
	shortBuffer = wav->getShortBuffer();
	rightShortBuffer = new short[(wav->getBufferSize())/2];
	leftShortBuffer = new short[(wav->getBufferSize())/2];
	std::cout << wav->getBufferSize() << std::endl;
	
	for(int j = 0; j < (wav->getBufferSize() - 2); j += 2){
		//std::cout << "short" << shortBuffer[i] << std::endl;
		leftShortBuffer[i] = shortBuffer[j];
		//std::cout << "left" << leftShortBuffer[i] << std::endl;
		rightShortBuffer[i] = shortBuffer[j + 1];
		//std::cout << "right" << rightShortBuffer[i] << std::endl;
		//std::cout << "j" << j << std::endl;
		//std::cout << "i" << i << std::endl;
		i++;
	}
}	

SixteenBitStereo::SixteenBitStereo(Wav* wav){
	std::cout << "hey from constructor" << std::endl;
	makeStereoBuffer(wav);
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
