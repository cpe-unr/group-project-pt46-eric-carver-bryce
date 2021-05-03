#ifndef EIGHTBITSTEREO_H
#define EIGHTBITSTEREO_H

#include "Wav.h"

class EightBitStereo: public Wav {
private:
	unsigned char *leftBuffer;
	unsigned char *rightBuffer;
	unsigned char *combinedBuffer;
public:
	/**
	Creates EightBitStereo object from wav object
	
	@param wav - copy of wav object
	*/
	EightBitStereo(const Wav& wav);
	/**
	Writes 8-bit Stereo wav files. 
	
	@param outFileName - name of new wav file
	*/
	void writeFile(const std::string &outFileName) override;
	/**
	Creates left and right buffer.
	
	@param wav - copy of wav object
	*/
	void makeStereoBuffer(const Wav& wav);
	/**
	Combines left and right buffers in to combinedBuffer.
	*/
	void combineBuffers();
	/**
	Gets left buffer.
	*/
	unsigned char *getLeftBuffer();
	/**
	Gets right buffer. 
	*/
	unsigned char *getRightBuffer();
};
#endif
