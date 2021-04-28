/** @file */
#include <iostream>
#include <vector>
#include <fstream>

#include "Wav.h"
#include "directory.h"

const std::string eightbitmono = "yes-8bit-mono.wav";
const std::string eightbitstereo = "yes-8-bit-stereo.wav";
const std::string sixteenbitmono = "yes-16-bit-mono.wav";
const std::string sixteenbitstereo = "yes-26-bit-stereo.wav";


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
		std::cout << "Correct Usage: ./audioprocessor audiofiles" <<std::endl;
		return 0;
	}

	Directory dir;
	std::vector<std::string> files;
	files = dir.getFileNames(argv[1]); //Audio files are stored in vector: files

	std::vector<Wav*> wavObjects;
	for(int i=0; i < files.size(); i++){ 
		Wav* wav = new Wav;
		wav->readFile(files[i]);
		wavObjects.push_back(wav); //Wav Objects that hold buffers 							and technical info in 							vector: wavObjects
		wav->~Wav();	
		std::cout << files[i] << std::endl;
	}

	return 0;
}
