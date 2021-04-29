#ifndef SIXTEENBITSTEREO_H
#define SIXTEENBITSTEREO_H

#include "Wav.h"

class SixteenBitStereo: public Wav {
private:
	short *leftShortBuffer = NULL;
	short *rightShortBuffer = NULL;
public:
	Wav *clone();
	SixteenBitStereo(Wav* wav);
	void makeStereoBuffer(Wav* wav);
	short *getLeftShortBuffer();
	short *getRightShortBuffer();
};
#endif
