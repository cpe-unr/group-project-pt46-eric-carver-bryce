#ifndef SIXTEENBITMONO_H
#define SIXTEENBITMONO_H

#include "Wav.h"

class SixteenBitMono: public Wav{
public:
	/**
	Returns getShortBuffer().
	@return Short Buffer
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
	/**
	Makes the compiler happy - does nothing useful
	
	@returns buffer
	*/
	short* getLeftBuffer(){return getBuffer();}
	/**
	Makes the compiler happy - does nothing useful
	
	@returns buffer
	*/
	short* getRightBuffer(){return getBuffer();}
};
#endif
