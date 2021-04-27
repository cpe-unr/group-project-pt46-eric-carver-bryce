#ifndef EIGHTBITSTEREO_H
#define EIGHTBITSTEREO_H

#include "Wav.h"

class EightBitStereo: public Wav {
private:
	unsigned char *leftBuffer;
	unsigned char *rightBuffer;
public:
	EightBitStereo(const EightBitStereo& wav);
	void makeStereoBuffer(const EightBitStereo& wav);
	unsigned char *getLeftBuffer();
	unsigned char *getRightBuffer();
};
#endif
