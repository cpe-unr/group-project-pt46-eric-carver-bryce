#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <dirent.h>

class Directory {
public:
	std::vector<std::string> getFileNames(const char* path);
	bool hasFiles(const char* path);

};
#endif
