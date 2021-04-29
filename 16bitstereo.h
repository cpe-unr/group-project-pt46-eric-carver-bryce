#ifndef SIXTEENBITSTEREO_H
#define SIXTEENBITSTEREO_H

#include "Wav.h"

class SixteenBitStereo: public Wav {
private:
	short *shortBuffer = NULL;
	short *leftShortBuffer = NULL;
	short *rightShortBuffer = NULL;
public:
	SixteenBitStereo(Wav* wav);
	void makeStereoBuffer(Wav* wav);
	short *getLeftBuffer();
	short *getRightBuffer();
	short *getBuffer() const;
};
#endif
