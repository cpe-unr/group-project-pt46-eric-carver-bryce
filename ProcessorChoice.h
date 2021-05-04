/** @file */
#include <iostream>
#include <vector>
#include <fstream>

#include "Wav.h"
#include "8bitmono.h"
#include "8bitstereo.h"
#include "16bitmono.h"
#include "16bitstereo.h"
#include "directory.h"
#include "Processor.h"
#include "Gui.h"

class ProcessorChoice{
	Wav* wavObject;
public:
	ProcessorChoice(Wav* inputObject){wavObject = inputObject;}
	void GetInput();
};
