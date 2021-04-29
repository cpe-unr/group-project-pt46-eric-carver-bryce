#ifndef SIXTEENBITMONO_H
#define SIXTEENBITMONO_H

#include "Wav.h"

class SixteenBitMono: public Wav{
public:
	short *getBuffer() const;

};
#endif
