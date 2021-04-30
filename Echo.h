#ifndef ECHO_H
#define ECHO_H
class Echo{
protected:
	/**
	Adds an echo on 8-bit buffer, specified in seconds
	
	@param Start of the buffer
	@param Size of the buffer
	@param Delay (in seconds) of the echo
	@param Scale factor of the echo (between 0 and 1)
	@param Frame rate (frames/second) of the data
	*/
	void EchoInSeconds(unsigned char* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate);
	/**
	Adds an echo on 16-bit buffer, specified in seconds
	
	@param Start of the buffer
	@param Size of the buffer
	@param Delay (in seconds) of the echo
	@param Scale factor of the echo (between 0 and 1)
	@param Frame rate (frames/second) of the data
	*/
	void EchoInSeconds(short* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate);
	/**
	Adds an echo on 8-bit buffer, specified in frames
	
	@param Start of the buffer
	@param Size of the buffer
	@param Delay (in frames) of the echo
	@param Scale factor of the echo (between 0 and 1)
	*/
	void EchoInFrames(unsigned char* buffer, int bufferSize, int delayInFrames, float scaleFactor);
	/**
	Adds an echo on 16-bit buffer, specified in frames
	
	@param Start of the buffer
	@param Size of the buffer
	@param Delay (in frames) of the echo
	@param Scale factor of the echo (between 0 and 1)
	*/
	void EchoInFrames(short* buffer, int bufferSize, int delayInFrames, float scaleFactor);
};
#endif
