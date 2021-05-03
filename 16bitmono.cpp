#include "16bitmono.h"

short *SixteenBitMono::getBuffer() const{
	return Wav::getShortBuffer();
}

SixteenBitMono::SixteenBitMono(const Wav& wav): Wav(wav) {}

void SixteenBitMono::writeFile(const std::string &outFileName){
}
