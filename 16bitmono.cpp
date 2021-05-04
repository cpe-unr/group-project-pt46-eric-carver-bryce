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
	outFile.write((char*)buffer, waveHeader.data_bytes);
	if (metadataHeader.metadataSize > 0){
		outFile.write((char const*)&metadataHeader,sizeof(MetadataHeader));
		for(Metadata storedMetadata : metadataVector){
			outFile.write((char*)&storedMetadata, 8);
			outFile.write((char*)(storedMetadata.metadata.data()), storedMetadata.metadata.length());
		}
	}
	outFile.close();
}
