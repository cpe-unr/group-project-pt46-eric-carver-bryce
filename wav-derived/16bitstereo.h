#ifndef 16BITSTEREO_H
#define 16BITSTEREO_H

#include "Wav.h"

class 16BitStereo: public Wav {
private:
	short *leftShortBuffer;
	short *rightShortBuffer;
public:
	16BitStereo();
	void makeLeftShortBuffer();
	void makeRightShortBuffer();
	short *getLeftShortBuffer();
	short *getRightShortBuffer();
};
#endif 16BITSTEREO_H
