#include "Echo.h"

void Echo::EchoInFrames(unsigned char* buffer, int bufferSize, int delayInFrames, float scaleFactor){
	int i = 0;
	while (i < bufferSize){
		int x = *(buffer+i);
		int y = *(buffer+i+delayInFrames);
		int z = (x-128)/scaleFactor+y;
		if (z<0){
			z=0;
		}
		if (z>256){
			z=256;
		}
		*(buffer+i+delayInFrames) = (unsigned char) z;
		i++;
	}
}
void Echo::EchoInFrames(short* buffer, int bufferSize, int delayInFrames, float scaleFactor){
	int i = 0;
	while (i < bufferSize){
		int x = *(buffer+i);
		int y = *(buffer+i+delayInFrames);
		int z = x/scaleFactor+y;
		if (z<-32767){
			z=-32767;
		}
		if (z>32767){
			z=32767;
		}
		*(buffer+i+delayInFrames) = (short) z;
		i++;
	}
}
void Echo::EchoInSeconds(unsigned char* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate){
	int delayInFrames = (int) delayInSeconds*frameRate;
	Echo::EchoInFrames(buffer, bufferSize, delayInFrames, scaleFactor);
}
void Echo::EchoInSeconds(short* buffer, int bufferSize, float delayInSeconds, float scaleFactor, int frameRate){
	int delayInFrames = (int) delayInSeconds*frameRate;
	Echo::EchoInFrames(buffer, bufferSize, delayInFrames, scaleFactor);
}
