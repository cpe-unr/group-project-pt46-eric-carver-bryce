#include <iostream>
#include <cstring>
#include "directory.h"

std::vector<std::string> Directory::getFileNames(const char* path){
	struct dirent *d;
	DIR *dr;
	dr = opendir(path);
	std::vector<std::string> files;
	std::string i = "audiofiles/";
	
	if(dr != NULL){
		while((d = readdir(dr)) != NULL){
			//std::cout << d->d_name << std::endl;
			if(!strcmp(d->d_name, ".") || !strcmp(d->d_name, "..")){
			}
			else{
			files.push_back(i + d->d_name);
			}
		}
	}
	
	else{}
	closedir(dr);

	return files;
}

bool hasFiles(int i){
	
}
