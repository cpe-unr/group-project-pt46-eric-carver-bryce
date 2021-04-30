#ifndef NORMALIZATION_H
#define NORMALIZATION_H
class Normalization{
protected:
	/**
	Normalizes 8-bit buffer, specified as a fraction
	
	@param Start of the buffer
	@param Size of the buffer
	@param Scale factor of the normalization (between 0 and 1)
	*/
	void NormalizationByPercent(unsigned char* buffer, int bufferSize, float scaleFactor);//scaleFactor should be between 0 and 1
	/**
	Normalizes 16-bit buffer, specified as a fraction
	
	@param Start of the buffer
	@param Size of the buffer
	@param Scale factor of the normalization (between 0 and 1)
	*/
	void NormalizationByPercent(short* buffer, int bufferSize, float scaleFactor);//scaleFactor should be between 0 and 1
	/**
	Normalizes 8-bit buffer, specified in decibels
	
	@param Start of the buffer
	@param Size of the buffer
	@param Decibels below maximum (should be at most 0)
	*/
	void NormalizationInDB(unsigned char* buffer, int bufferSize, float db);//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
	/**
	Normalizes 16-bit buffer, specified in decibels
	
	@param Start of the buffer
	@param Size of the buffer
	@param Decibels below maximum (should be at most 0)
	*/
	void NormalizationInDB(short* buffer, int bufferSize, float db);//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
};
#endif
