#include "8bitstereo.h"

void EightBitStereo::makeStereoBuffer(const EightBitStereo& wav){
	leftBuffer = wav.getBuffer();
	for(int i = 0; i < wav.getBufferSize(); i++){
		leftBuffer[i + 1] = rightBuffer[i];
		leftBuffer[i + 2] = leftBuffer[i + 1];
	}
}	

EightBitStereo::EightBitStereo(const EightBitStereo& wav){
	makeStereoBuffer(wav);
}

unsigned char *EightBitStereo::getLeftBuffer(){
	return leftBuffer;
}
unsigned char *EightBitStereo::getRightBuffer(){
	return rightBuffer;
}
