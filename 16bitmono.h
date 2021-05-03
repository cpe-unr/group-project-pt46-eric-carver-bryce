#ifndef SIXTEENBITMONO_H
#define SIXTEENBITMONO_H

#include "Wav.h"

class SixteenBitMono: public Wav{
public:
	/**
	Returns getShortBuffer().
	*/
	short *getBuffer() const;
	/**
	Creates SixteenBitMono object from wav object.
	
	@param wav - copy of wav object
	*/
	SixteenBitMono(const Wav& wav);
	/**
	Writes 16-bit Mono wav files.
	
	@param outFileName - name of new wav file
	*/
	void writeFile(const std::string &outFileName) override;

};
#endif
