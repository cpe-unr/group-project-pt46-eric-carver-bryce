#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Echo.h"
#include "Normalization.h"

template <class C>
class Processor: public Echo, public Normalization{
private:
	C* wav;
public:
	Processor(C* wavObject){wav = wavObject;}
	void EchoSeconds(float seconds, float scaleFactor){
		if (wav->isStereo()){
			EchoInSeconds(wav->getLeftBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
			EchoInSeconds(wav->getRightBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
		}else{
			EchoInSeconds(wav->getBuffer(), wav->getBufferSize(), seconds, scaleFactor, wav->getWaveHeader().sample_rate);
		}
	}
	void EchoFrames(int frames, float scaleFactor){
		if (wav->isStereo()){
			EchoInFrames(wav->getLeftBuffer(), wav->getBufferSize(), frames, scaleFactor);
			EchoInFrames(wav->getRightBuffer(), wav->getBufferSize(), frames, scaleFactor);
		}else{
			EchoInFrames(wav->getBuffer(), wav->getBufferSize(), frames, scaleFactor);
		}
	}
	void NormalizeDecibels(float decibels){
		if (wav->isStereo()){
			NormalizationInDB(wav->getLeftBuffer(), wav->getBufferSize(), decibels);
			NormalizationInDB(wav->getRightBuffer(), wav->getBufferSize(), decibels);
		}else{
			NormalizationInDB(wav->getBuffer(), wav->getBufferSize(), decibels);
		}
	}
	void NormalizePercent(float percent){
		if (wav->isStereo()){
			NormalizationByPercent(wav->getLeftBuffer(), wav->getBufferSize(), percent/100);
			NormalizationByPercent(wav->getRightBuffer(), wav->getBufferSize(), percent/100);
		}else{
			NormalizationByPercent(wav->getBuffer(), wav->getBufferSize(), percent/100);
		}
	}
	void NormalizeFraction(float fraction){
		if (wav->isStereo()){
			NormalizationByPercent(wav->getLeftBuffer(), wav->getBufferSize(), fraction);
			NormalizationByPercent(wav->getRightBuffer(), wav->getBufferSize(), fraction);
		}else{
			NormalizationByPercent(wav->getBuffer(), wav->getBufferSize(), fraction);
		}
	}
};
#endif
