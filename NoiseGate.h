#ifndef NOISEGATE_H
#define NOISEGATE_H
class NoiseGate{
protected:
	void NoiseGateByPercent(unsigned char* buffer, int bufferSize, float cutoffFraction);
	void NoiseGateByPercent(short* buffer, int bufferSize, float cutoffFraction);
	void NoiseGateByFlat(unsigned char* buffer, int bufferSize, int cutoff);
	void NoiseGateByFlat(short* buffer, int bufferSize, int cutoff);
};
#endif
