#include <string>
#include <vector>
#include <dirent.h>

class Directory {
private:
	std::string path;
public:
	vector<string> getFileNames(std::string path);

};
