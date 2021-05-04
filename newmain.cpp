/** @file */
#include <iostream>
#include <vector>
#include <fstream>

#include "Wav.h"
#include "directory.h"
#include "Processor.h"
#include "ProcessorChoice.h"

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "Correct Usage: " << argv[0] << " audiofiles" <<std::endl;
		return 0;
	}
	return 0;
}
