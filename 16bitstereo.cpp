#include "16bitstereo.h"

void SixteenBitStereo::makeStereoBuffer(const SixteenBitStereo& wav){
	leftShortBuffer = wav.getShortBuffer();
	for(int i = 0; i < wav.getBufferSize(); i++){
		leftShortBuffer[i + 1] = rightShortBuffer[i];
		leftShortBuffer[i + 2] = leftShortBuffer[i + 1];
	}
}	

SixteenBitStereo::SixteenBitStereo(const SixteenBitStereo& wav){
	makeStereoBuffer(wav);
}

short *SixteenBitStereo::getLeftShortBuffer(){
	return leftShortBuffer;
}
short *SixteenBitStereo::getRightShortBuffer(){
	return rightShortBuffer;
}
