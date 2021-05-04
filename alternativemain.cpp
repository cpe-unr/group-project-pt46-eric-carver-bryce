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
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
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
		std::cout << "Will create " << files[i] << std::endl;//TEST TEST TEST
		Wav* wav = Wav::Create(files[i]);
		wavObjects.push_back(wav); //Wav Objects that hold buffers 							and technical info in 							vector: wavObjects
		wav->~Wav();	
	}
	std::cout << "Has created." << std::endl;//TEST TEST TEST
	for(int i=0; i < wavObjects.size(); i++){
		ProcessorChoice chooser(wavObjects[i]);
		int x;
		while(x != 0 || x != 1){
			std::cout << files[i] << std::endl;
			std::cout << "Would you like to edit the metadata for this file? 0) No 1) Yes" << std::endl;
			std::cin >> x;
		}
		
		if(x == 1){
			wavObjects[i]->editMetadata();
		}	
	}

	CSVMenu csv;
	csv.runCSVMenu(wavObjects, files);


	return 0;
}
