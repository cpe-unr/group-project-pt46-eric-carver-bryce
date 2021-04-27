void 16BitStereo::makeLeftShortBuffer(){
}	
void 16BitStereo::makeRightShortBuffer(){
}

16BitStereo::16BitStereo(): makeRightShortBuffer(), makeRightShortBuffer() {};
short *16BitStereo::getLeftShortBuffer(){
	return leftShortBuffer;
}
short *16BitStereo::getRightShortBuffer(){
	return rightShortBuffer;
}
