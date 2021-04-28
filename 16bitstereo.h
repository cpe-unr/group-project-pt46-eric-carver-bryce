#ifndef SIXTEENBITSTEREO_H
#define SIXTEENBITSTEREO_H

#include "Wav.h"

class SixteenBitStereo: public Wav {
private:
	short *leftShortBuffer;
	short *rightShortBuffer;
public:
	SixteenBitStereo(Wav* wav);
	void makeStereoBuffer(const SixteenBitStereo& wav);
	short *getLeftShortBuffer();
	short *getRightShortBuffer();
};
#endif
