#include "Normalization.h"
#include <cmath>
void Normalization::NormalizationByPercent(unsigned char* buffer, int bufferSize, float scaleFactor){//scaleFactor should be between 0 and 1
	int i = 0;
	unsigned char highest = 128;
	unsigned char lowest = 128;
	while (i < bufferSize){
		if (*(buffer+i) > highest){
			highest = *(buffer+i);
			lowest = 256 - *(buffer+i);
		}else if(*(buffer+i) < lowest){
			highest = 256 - *(buffer+i);
			lowest = *(buffer+i);
		}
		i++;
	}
	i = 0;
	float scale = 128.0*scaleFactor/highest;
	while (i < bufferSize){
		*(buffer+i) = 128+(*(buffer+i))*(scale-128);
		i++;
	}
}
void Normalization::NormalizationByPercent(short* buffer, int bufferSize, float scaleFactor){//scaleFactor should be between 0 and 1
	int i = 0;
	short highest = 0;
	while (i < bufferSize){
		if (abs(*(buffer+i)) > highest){
			highest = abs(*(buffer+i));
		}
		i++;
	}
	i = 0;
	float scale = 32767.0*scaleFactor/highest;
	while (i < bufferSize){
		*(buffer+i) = (*(buffer+i))*scale;
		i++;
	}
}
void Normalization::NormalizationInDB(unsigned char* buffer, int bufferSize, float db){//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
	float scaleFactor = pow(10, db/10.0);
	Normalization::NormalizationByPercent(buffer, bufferSize, scaleFactor);
}
void Normalization::NormalizationInDB(short* buffer, int bufferSize, float db){//db should be negative or 0 (0 meaning bring peak amplitude to maximum)
	float scaleFactor = pow(10, db/10.0);
	Normalization::NormalizationByPercent(buffer, bufferSize, scaleFactor);
}
