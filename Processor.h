#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Echo.h"
#include "Normalization.h"
#include "NoiseGate.h"

template <class C>
class Processor: public Echo, public Normalization, public NoiseGate{
private:
	C* wav;
public:
	/**
	Constructor for the Processor class
	
	@param Pointer to the Wav Object
	@return Processor Object
	*/
	Processor(C* wavObject){wav = wavObject;}
	/**
	Applies an echo to the buffer, specified in seconds
	
	@param Delay in seconds
	@param Factor to scale the echo (between 0 and 1)
	*/
	void EchoSeconds(float seconds, float scaleFactor){
		if (wav->isStereo()){
			EchoInSeconds(wav->getLeftBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
			EchoInSeconds(wav->getRightBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
		}else{
			EchoInSeconds(wav->getBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
		}
	}
	/**
	Applies an echo to the buffer, specified in frames
	
	@param Delay in frames
	@param Factor to scale the echo (between 0 and 1)
	*/
	void EchoFrames(int frames, float scaleFactor){
		if (wav->isStereo()){
			EchoInFrames(wav->getLeftBuffer(), wav->getBufferSize(), frames, scaleFactor);
			EchoInFrames(wav->getRightBuffer(), wav->getBufferSize(), frames, scaleFactor);
		}else{
			EchoInFrames(wav->getBuffer(), wav->getBufferSize(), frames, scaleFactor);
		}
	}
	/**
	Applies normalization to the buffer, specified in decibels from maximum
	
	@param Number of decibels from max to normalize the peak to (should be negative)
	*/
	void NormalizeDecibels(float decibels){
		if (wav->isStereo()){
			NormalizationInDB(wav->getLeftBuffer(), wav->getBufferSize(), decibels);
			NormalizationInDB(wav->getRightBuffer(), wav->getBufferSize(), decibels);
		}else{
			NormalizationInDB(wav->getBuffer(), wav->getBufferSize(), decibels);
		}
	}
	/**
	Applies normalization to the buffer, specified in percent of maximum
	
	@param Percent of max to normalize the peak to (should be negative)
	*/
	void NormalizePercent(float percent){
		if (wav->isStereo()){
			NormalizationByPercent(wav->getLeftBuffer(), wav->getBufferSize(), percent/100.0);
			NormalizationByPercent(wav->getRightBuffer(), wav->getBufferSize(), percent/100.0);
		}else{
			NormalizationByPercent(wav->getBuffer(), wav->getBufferSize(), percent/100.0);
		}
	}
	/**
	Applies normalization to the buffer, specified by decimal of maximum
	
	@param Decimal of max to normalize the peak to (should be negative)
	*/
	void NormalizeFraction(float fraction){
		if (wav->isStereo()){
			NormalizationByPercent(wav->getLeftBuffer(), wav->getBufferSize(), fraction);
			NormalizationByPercent(wav->getRightBuffer(), wav->getBufferSize(), fraction);
		}else{
			NormalizationByPercent(wav->getBuffer(), wav->getBufferSize(), fraction);
		}
	}
	/**
	Applies noise gate to the buffer, specified by mininum level
	
	@param Integer to apply noise gate when below
	*/
	void NoiseGateLevel(int level){
		if (wav->isStereo()){
			NoiseGateByFlat(wav->getLeftBuffer(), wav->getBufferSize(), level);
			NoiseGateByFlat(wav->getRightBuffer(), wav->getBufferSize(), level);
		}else{
			NoiseGateByFlat(wav->getBuffer(), wav->getBufferSize(), level);
		}
	}
	/**
	Applies noise gate to the buffer, specified by percent
	
	@param Percent of maximum to apply noise gate when below
	*/
	void NoiseGatePercent(float percent){
		if (wav->isStereo()){
			NoiseGateByPercent(wav->getLeftBuffer(), wav->getBufferSize(), percent/100.0);
			NoiseGateByPercent(wav->getRightBuffer(), wav->getBufferSize(), percent/100.0);
		}else{
			NoiseGateByPercent(wav->getBuffer(), wav->getBufferSize(), percent/100.0);
		}
	}
	/**
	Applies noise gate to the buffer, specified by decimal
	
	@param Decimal of maximum to apply noise gate when below
	*/
	void NoiseGateFraction(float fraction){
		if (wav->isStereo()){
			NoiseGateByPercent(wav->getLeftBuffer(), wav->getBufferSize(), fraction);
			NoiseGateByPercent(wav->getRightBuffer(), wav->getBufferSize(), fraction);
		}else{
			NoiseGateByPercent(wav->getBuffer(), wav->getBufferSize(), fraction);
		}
	}
};
#endif
