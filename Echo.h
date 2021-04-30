#ifndef ECHO_H
#define ECHO_H
class Echo{
protected:
	void EchoInSeconds(unsigned char* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate);
	void EchoInSeconds(short* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate);
	void EchoInFrames(unsigned char* buffer, int bufferSize, int delayInFrames, float scaleFactor);
	void EchoInFrames(short* buffer, int bufferSize, int delayInFrames, float scaleFactor);
};
#endif
