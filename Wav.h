//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"
#include "Metadata.h"
#include <string>
#include <vector>


class Wav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
    std::vector<Metadata*> metadataVector;
public:
    virtual ~Wav();
    Wav();
    Wav(const Wav& rhs);
    static Wav *Create(const std::string &fileName);

public:
    unsigned char *getBuffer() const;
    short *getShortBuffer() const;
    int getBufferSize() const;
    wav_header getWaveHeader();
    void setWaveHeader(wav_header* header);
    bool isStereo();
    bool is16Bit();
    static void makeCSV();
    void addToCSV(std::string filename);
};
#endif //WAV_H
