#include "16bitmono.h"

#include <fstream>

short *SixteenBitMono::getBuffer() const{
	return Wav::getShortBuffer();
}

SixteenBitMono::SixteenBitMono(const Wav& wav): Wav(wav) {}

void SixteenBitMono::writeFile(const std::string &outFileName){
 	wav_header waveHeader = Wav::getWaveHeader();
	short* buffer = SixteenBitMono::getBuffer();

	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char const*)buffer, waveHeader.data_bytes);
	outFile.close();
}
