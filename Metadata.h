#include <string>
struct Metadata{
	char chunkheader[4];
	int length;
	std::string metadata;
};
struct MetadataHeader{
	char list[4];
	int metadataSize;
	char info[4];
};
