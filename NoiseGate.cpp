#include "NoiseGate.h"
void NoiseGate::NoiseGateByPercent(unsigned char* buffer, int bufferSize, float cutoffFraction){//cutoffFraction should be positive
	int cutoff = 128+cutoffFraction*127;
	NoiseGate::NoiseGateByFlat(buffer, bufferSize, cutoff);
}
void NoiseGate::NoiseGateByPercent(short* buffer, int bufferSize, float cutoffFraction){//cutoffFraction should be positive
	int cutoff = cutoffFraction*32767;
	NoiseGate::NoiseGateByFlat(buffer, bufferSize, cutoff);
}
void NoiseGate::NoiseGateByFlat(unsigned char* buffer, int bufferSize, int cutoff){//cutoff should be greater than 128
	int i = 0;
	int lastzero = 0;
	bool gateClosed = false;
	int loopGuard = -1;
	while (i < bufferSize){
		if ((*buffer+i)==128){
			lastzero = i;
		}
		short leftdiff = *(buffer+i)-*(buffer+i-1);
		short rightdiff = *(buffer+i)-*(buffer+i+1);
		if ((leftdiff >= 0 && rightdiff >= 0) || (leftdiff <= 0 && rightdiff <= 0)){
			if ((i != loopGuard) && (*(buffer+i)<cutoff || *(buffer+i)>256-cutoff)){
				gateClosed = true;
				loopGuard = i;
				i = lastzero;
			}
		}
		if (gateClosed){
			if (*(buffer+i)<cutoff || *(buffer+i)>256-cutoff){
				*(buffer+i) = 128;
			}else{
				gateClosed = false;
			}
		}
		i++;
	}
}
void NoiseGate::NoiseGateByFlat(short* buffer, int bufferSize, int cutoff){//cutoff should be greater than 0
	int i = 0;
	int lastzero = 0;
	bool gateClosed = false;
	int loopGuard = -1;
	while (i < bufferSize){
		if ((*buffer+i)==0){
			lastzero = i;
		}
		short leftdiff = *(buffer+i)-*(buffer+i-1);
		short rightdiff = *(buffer+i)-*(buffer+i+1);
		if ((leftdiff >= 0 && rightdiff >= 0) || (leftdiff <= 0 && rightdiff <= 0)){
			if ((i != loopGuard) && (*(buffer+i)<cutoff || *(buffer+i)>-cutoff)){
				gateClosed = true;
				loopGuard = i;
				i = lastzero;
			}
		}
		if (gateClosed){
			if (*(buffer+i)<cutoff || *(buffer+i)>-cutoff){
				*(buffer+i) = 0;
			}else{
				gateClosed = false;
			}
		}
		i++;
	}
}
