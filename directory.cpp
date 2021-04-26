#include <iostream>
#include "directory.h"

vector<string> Directory::getFileNames(std::string path){
	
	for(const auto & entry : fs::directory_iterator(path)){
		std::cout << entry.path << std::endl;
		i++
	}
}
