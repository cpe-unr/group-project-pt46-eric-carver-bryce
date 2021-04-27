#include "Processor8bit.h"

void Processor8bit::EchoInSeconds(unsigned char* buffer, int bufferSize, float delayInSeconds, float scaleFactor){
	int i = 0;
	int delay = (int) delayInSeconds*1;//REPLACE THE 1 WITH FRAME RATE
	while (i < bufferSize){
		int x = *(buffer+i);
		int y = *(buffer+i+delay);
		int z = (x-128)/scaleFactor+y;
		if (z<0){
			z=0;
		}
		if (z>256){
			z=256;
		}
		*(buffer+i+delay) = (unsigned char) z;
		i++;
	}
}
void Processor8bit::EchoInFrames(unsigned char* buffer, int bufferSize, int delayInFrames, float scaleFactor){
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
