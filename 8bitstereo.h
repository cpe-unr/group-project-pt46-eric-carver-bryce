#ifndef EIGHTBITSTEREO_H
#define EIGHTBITSTEREO_H

#include "Wav.h"

class EightBitStereo: public Wav {
private:
	unsigned char *leftBuffer;
	unsigned char *rightBuffer;
	unsigned char *combinedBuffer;
public:
	EightBitStereo(const Wav& wav);
	//EightBitStereo(const EightBitStereo& rhs);
	void writeFile(const std::string &outFileName) override;
	void makeStereoBuffer(const Wav& wav);
	void combineBuffers();
	unsigned char *getLeftBuffer();
	unsigned char *getRightBuffer();
};
#endif
