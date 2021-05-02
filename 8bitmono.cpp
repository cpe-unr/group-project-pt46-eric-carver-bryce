#include "8bitmono.h"
#include <iostream>

/*void EightBitMono::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}*/

EightBitMono::EightBitMono(const Wav& wav): Wav(wav) {}

