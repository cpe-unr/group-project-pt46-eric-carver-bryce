#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"
#include "Metadata.h"
#include <string>
#include <vector>


class Wav {
public:
	/**
	Reads in wav file, saving it's waveHeader info, audio data and metadata. 
	
	@param fileName - name of wav file
	*/
	void readFile(const std::string &fileName);

	/**
	Writes wav file based on type of file. 
	
	@param outFileName - name of new wav file
	*/
	virtual void writeFile(const std::string &outFileName){}
private:
	unsigned char* buffer = NULL;
	wav_header waveHeader;
protected:
	std::vector<Metadata> metadataVector;
	MetadataHeader metadataHeader;
public:
	/**
	Destructor
	*/
	virtual ~Wav();
	/**
	Default constructor.
	*/
	Wav();
	/**
	Copy constructor

	@param rhs - Wav object to be copied
	*/
	Wav(const Wav& rhs);
	/**
	Calls readFile() and creates new Wav object pointer based on file type.

	@param - fileName - name of wav file
	*/
	static Wav *Create(const std::string &fileName);

public:
	/**
	Gets copy of audio buffer.
	*/
	unsigned char *getBuffer() const;
	/**
	Gets 16-bit buffer.
	*/
	short *getShortBuffer() const;
	/**
	Gets size of buffer.
	*/
	int getBufferSize() const;
	/**
	Gets copy of waveHeader.
	*/
	wav_header getWaveHeader();
	/**
	Determines whether wav file is Stereo or Mono.
	*/
	bool isStereo();
	/**
	Determines whether wav file is 8 or 16 bit.
	*/
	bool is16Bit();
	/**
	Creates CSV with format.
	*/
	static void makeCSV();
	/**
	Adds wav file name and technical information to CSV.

	@param - filename - name of wav file
	*/
	void addToCSV(std::string filename);

	std::vector<Metadata> getMetadataVector();
	void editMetadata();
};
#endif //WAV_H
