#ifndef CSVMENU_H
#define CSVMENU_H

#include "Wav.h"
#include <vector>

class CSVMenu {
public:
	/**
	Runs CSV Menu and creates CSV if User requests
	
	@param Vector of Wav Objects
	@param Vector of File Names
	*/
	void runCSVMenu(std::vector<Wav *> wavObjects, std::vector<std::string> files);
};
#endif

