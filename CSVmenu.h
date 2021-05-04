#ifndef CSVMENU_H
#define CSVMENU_H

#include "Wav.h"
#include <vector>

class CSVMenu {
public:
	void runCSVMenu(std::vector<Wav *> wavObjects, std::vector<std::string> files);
};
#endif

