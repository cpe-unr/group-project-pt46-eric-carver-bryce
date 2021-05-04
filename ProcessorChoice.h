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
	/**
	Constructor
	
	@param Wav Object
	*/
	ProcessorChoice(Wav *inputObject){wavObject = inputObject;}
	/**
	Runs processor menu and applies processor if user requests. 
	*/
	void GetInput();
};
