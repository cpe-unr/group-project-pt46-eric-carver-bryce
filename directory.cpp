#include <iostream>
#include "directory.h"

std::vector<std::string> Directory::getFileNames(const char* path){
	
	struct dirent *d;
	DIR *dr;
	dr = opendir(path);
	std::vector<std::string> files;
	
	if(dr != NULL){
		while((d = readdir(dr)) != NULL){
			//std::cout << d->d_name << std::endl;
			files.push_back(d->d_name);
		}
	}
	
	else{
	}

	return files;
}
