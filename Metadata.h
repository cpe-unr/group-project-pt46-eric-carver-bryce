#include <string>
struct Metadata{
	char chunkheader[4];
	int length;
	std::string metadata;
};
