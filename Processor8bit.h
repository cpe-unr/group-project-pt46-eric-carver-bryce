#ifndef PROCESSOR_8_BIT_H
#define PROCESSOR_8_BIT_H
class Processor8bit{
public:
	void EchoInSeconds(unsigned char* buffer, int bufferSize, float delayInSeconds, float scaleFactor);
	void EchoInFrames(unsigned char* buffer, int bufferSize, int delayInFrames, float scaleFactor);
};
#endif
