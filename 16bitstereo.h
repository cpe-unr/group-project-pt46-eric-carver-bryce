#ifndef SIXTEENBITSTEREO_H
#define SIXTEENBITSTEREO_H

#include "Wav.h"

class SixteenBitStereo: public Wav {
private:
	short *shortBuffer = NULL;
	short *leftShortBuffer = NULL;
	short *rightShortBuffer = NULL;
public:
	/**
	Creates SixteenBitStereo object from wav object.
	
	@param wav - copy of wav object
	*/
	SixteenBitStereo(const Wav& wav);
	/**
	Copy Constructor
	
	@param rhs - SixteenBitStereo object to be copied
	*/
	SixteenBitStereo(const SixteenBitStereo& rhs);
	/**
	Writes 16-bit Stereo wav files.
	
	@param outFileName - name of new wav file
	*/
	void writeFile(const std::string &outFileName) override;
	/**
	Creates left and right buffer from short buffer.
	
	@param wav - copy of wav object
	*/
	void makeStereoBuffer(const Wav& wav);
	/**
	Gets left Buffer.
	*/
	short *getLeftBuffer();
	/**
	Gets right Buffer. 
	*/
	short *getRightBuffer();
	/**
	Gets short Buffer.
	*/
	short *getBuffer() const;
	/**
	Combines left and right buffers in to shortBuffer.  
	*/
	void combineBuffers();
};
#endif
