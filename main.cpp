/** @file */
#include <iostream>
#include <vector>
#include <fstream>

#include "Wav.h"
#include "directory.h"
#include "Processor.h"
#include "Gui.h"

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
		std::cout << "Correct Usage: " << argv[0] << " audiofiles" <<std::endl;
		return 0;
	}

	/*Directory dir;
	std::vector<std::string> files;
	files = dir.getFileNames(argv[1]); //Audio files are stored in vector: files

	std::vector<Wav*> wavObjects;
	Wav::makeCSV();
	for(int i=0; i < files.size(); i++){ 
		Wav* wav = Wav::Create(files[i]);
		wavObjects.push_back(wav); //Wav Objects that hold buffers 							and technical info in 							vector: wavObjects
		wav->addToCSV(files[i]);
		wav->editMetadata();
		wav->~Wav();	
		std::cout << files[i] << std::endl;
	}*/
		
	bool mainMenuShouldExit = false;
	bool fileMenuShouldExit = false;	
	int fileChoice = 0;
	while( !mainMenuShouldExit )
	{
		Gui::MainMenu::MENU_CHOICE mainMenuChoice   = 		Gui::MainMenu::getMenuChoice();
	int processingMenuChoice = 0;	
	switch( mainMenuChoice )
		{
		case Gui::FileMenu::PROCESS:
					{
						//int processingMenuChoice = 0;
						while( processingMenuChoice = Gui::ProcessingMenu::getMenuChoice() )
						{
							if( processingMenuChoice == Gui::ProcessingMenu::UNKNOWN )
							{
						std::cout << "Unknown option choice" << std::endl;
continue;
						}
						if( processingMenuChoice & Gui::ProcessingMenu::NORMALISATION )
						{
						std::cout << "Normlising" << std::endl;
						}
						if( processingMenuChoice & Gui::ProcessingMenu::NOISE_GATING )
						{
						std::cout << "Noise Gating" << std::endl;
						}
						if( processingMenuChoice & Gui::ProcessingMenu::ECHO )
						{
						std::cout << "Echo" << std::endl;
						}
					}
					break;
	case Gui::MainMenu::FILE:
	{
			
			while( !fileMenuShouldExit )
			{
				{
				Gui::FileMenu::MENU_CHOICE fileMenuChoice = Gui::FileMenu::getMenuChoice();
				fileChoice = fileMenuChoice;
				switch( fileMenuChoice )
				{
				case Gui::FileMenu::EXIT:
					std::cout << "Goodbye" << std::endl;
							return 0;
					break;
				case Gui::FileMenu::EDIT_FILE_NAME:
					std::cout << "Editing Filename" << std::endl;
					break;
				
				}
				}
				
				break;
			case Gui::FileMenu::EXIT:
				fileMenuShouldExit = true;
				break;
			default:
	std::cerr << "Invalid option " << (int)fileChoice << std::endl;		
			}
		}
	}
	break;
case Gui::MainMenu::EXIT:
	mainMenuShouldExit = true;
	break;
default:
	std::cerr << "Invalid option " << (int)mainMenuChoice << std::endl;
}

	}


	return 0;
}
