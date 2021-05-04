/** @file */
#include <iostream>
#include <vector>
#include <fstream>

#include "Wav.h"
#include "directory.h"
#include "Processor.h"
#include "ProcessorChoice.h"
#include "Gui.h"
#include "CSVmenu.h"

/**
 * Main Function
 * 
 */
void fn(){

}

int main(int argc, char* argv[]) {
	
	if(argc != 2){
		std::cout << "Correct Usage: " << argv[0] << " audiofiles" <<std::endl;
		return 0;
	}

	Directory dir;
	std::vector<std::string> files;
	files = dir.getFileNames(argv[1]); //Audio files are stored in vector: files
	
	std::vector<Wav*> wavObjects;
	for(int i=0; i < files.size(); i++){ 
		Wav* wav = Wav::Create(files[i]);
		wavObjects.push_back(wav); //Wav Objects that hold buffers 							and technical info in 							vector: wavObjects
		wav->~Wav();	
	}
	for(int i=0; i < wavObjects.size(); i++){
		std::cout << files[i] << std::endl;
		ProcessorChoice chooser(wavObjects[i]);
		chooser.GetInput();
		int x;
		while(x != 0 && x != 1){
			std::cout << files[i] << std::endl;
			std::cout << "Would you like to edit the metadata for this file? 0) No 1) Yes" << std::endl;
			std::cin >> x;
		}
		
		if(x == 1){
			wavObjects[i]->editMetadata();
		}	
		x = 2;
	}

	CSVMenu csv;
	csv.runCSVMenu(wavObjects, files);


	return 0;
}
