#include "8bitmono.h"
#include <iostream>
#include <fstream>

void EightBitMono::writeFile(const std::string &outFileName) {
    wav_header waveHeader = Wav::getWaveHeader();
    unsigned char* buffer = Wav::getBuffer();

    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

EightBitMono::EightBitMono(const Wav& wav): Wav(wav) {}

