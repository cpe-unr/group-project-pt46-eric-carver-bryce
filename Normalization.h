#ifndef NORMALIZATION_H
#define NORMALIZATION_H
class Normalization{
protected:
	void NormalizationByPercent(unsigned char* buffer, int bufferSize, float scaleFactor);//scaleFactor should be between 0 and 1
	void NormalizationByPercent(short* buffer, int bufferSize, float scaleFactor);//scaleFactor should be between 0 and 1
	void NormalizationInDB(unsigned char* buffer, int bufferSize, float db);//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
	void NormalizationInDB(short* buffer, int bufferSize, float db);//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
};
#endif
