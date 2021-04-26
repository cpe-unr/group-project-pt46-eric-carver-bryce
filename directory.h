#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <dirent.h>

class Directory {
private:
	std::string path;
public:
	std::vector<std::string> getFileNames(const char* path);

};
#endif
