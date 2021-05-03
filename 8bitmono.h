#ifndef EIGHTBITMONO_H
#define EIGHTBITMONO_H

#include "Wav.h"

class EightBitMono: public Wav{
public:
	void writeFile(const std::string &outFileName) override;
	EightBitMono(const Wav& wav);


};
#endif
