#ifndef EIGHTBITMONO_H
#define EIGHTBITMONO_H

#include "Wav.h"

class EightBitMono: public Wav{
public:
	/**
	Writes 8-Bit Mono wav files.   
	
	@param outFileName - name of new wav file
	*/
	void writeFile(const std::string &outFileName) override;
	/**
	Creates EightBitMono object from wav object.
	
	@param wav - wav object
	*/
	EightBitMono(const Wav& wav);
	/**
	Makes the compiler happy - does nothing useful
	
	@returns buffer
	*/
	unsigned char* getLeftBuffer(){return getBuffer();}
	/**
	Makes the compiler happy - does nothing useful
	
	@returns buffer
	*/
	unsigned char* getRightBuffer(){return getBuffer();}
};
#endif
