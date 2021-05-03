#ifndef SIXTEENBITMONO_H
#define SIXTEENBITMONO_H

#include "Wav.h"

class SixteenBitMono: public Wav{
public:
	short *getBuffer() const;
	SixteenBitMono(const Wav& wav);
	void writeFile(const std::string &outFileName) override;

};
#endif
