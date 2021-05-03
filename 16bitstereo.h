#ifndef SIXTEENBITSTEREO_H
#define SIXTEENBITSTEREO_H

#include "Wav.h"

class SixteenBitStereo: public Wav {
private:
	short *shortBuffer = NULL;
	short *leftShortBuffer = NULL;
	short *rightShortBuffer = NULL;
public:
	SixteenBitStereo(const Wav& wav);
	SixteenBitStereo(const SixteenBitStereo& rhs);
	void writeFile(const std::string &outFileName) override;
	void makeStereoBuffer(const Wav& wav);
	short *getLeftBuffer();
	short *getRightBuffer();
	short *getBuffer() const;
};
#endif
