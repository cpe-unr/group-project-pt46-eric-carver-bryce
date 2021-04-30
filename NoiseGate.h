#ifndef NOISEGATE_H
#define NOISEGATE_H
class NoiseGate{
protected:
	/**
	Applies Noise Gate to 8-bit buffer, specified by decimal of signal
	
	@param Start of the buffer
	@param Size of the buffer
	@param Ratio of max signal to gate (should be between 0 and 1)
	*/
	void NoiseGateByPercent(unsigned char* buffer, int bufferSize, float cutoffFraction);
	/**
	Applies Noise Gate to 16-bit buffer, specified by decimal of signal
	
	@param Start of the buffer
	@param Size of the buffer
	@param Ratio of max signal to gate (should be between 0 and 1)
	*/
	void NoiseGateByPercent(short* buffer, int bufferSize, float cutoffFraction);
	/**
	Applies Noise Gate to 8-bit buffer, specified by value
	
	@param Start of the buffer
	@param Size of the buffer
	@param Max signal level to gate
	*/
	void NoiseGateByFlat(unsigned char* buffer, int bufferSize, int cutoff);
	/**
	Applies Noise Gate to 16-bit buffer, specified by value
	
	@param Start of the buffer
	@param Size of the buffer
	@param Max signal level to gate
	*/
	void NoiseGateByFlat(short* buffer, int bufferSize, int cutoff);
};
#endif
