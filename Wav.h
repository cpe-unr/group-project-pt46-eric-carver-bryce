//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"
#include <string>


class Wav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
public:
    virtual ~Wav();

public:
    unsigned char *getBuffer() const;
    short *getShortBuffer() const;
    int getBufferSize() const;
    wav_header getWaveHeader();
    int getChannels() const;
    int getBitDepth() const;

    Wav *cast();
};
#endif //WAV_H
