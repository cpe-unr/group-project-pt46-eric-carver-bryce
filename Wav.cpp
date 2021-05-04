#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Wav.h"
#include "16bitstereo.h"
#include "8bitstereo.h"
#include "16bitmono.h"
#include "8bitmono.h"

void Wav::readFile(const std::string &fileName) {
    std::ifstream file;
    file.open(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
       	file.read((char*)&metadataHeader, sizeof(MetadataHeader));
       	if(metadataHeader.info[0] == 'I' && metadataHeader.info[1] == 'N' && metadataHeader.info[2] == 'F' && metadataHeader.info[3] == 'O'){
       		int x = metadataHeader.metadataSize - 4;
       		while(x>0){
       			Metadata newMetadata;
       			file.read((char*)&newMetadata, 8);
       			newMetadata.metadata.resize(newMetadata.length);
       			file.read((char*)(newMetadata.metadata.data()), newMetadata.length);
       			x = x-(8+newMetadata.length);
       			metadataVector.push_back(newMetadata);
       		}
       	}
        file.close();
    }
}

unsigned char *Wav::getBuffer() const{
    return buffer;
}

short *Wav::getShortBuffer() const{
    short* shortBuffer = reinterpret_cast<short*>(buffer);
    return shortBuffer;
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

Wav *Wav::Create(const std::string &fileName){
	Wav wav;
	wav.readFile(fileName);
	if(wav.isStereo()){
		if(wav.is16Bit()){
			return new SixteenBitStereo(wav);
		}
		
		else{
			return new EightBitStereo(wav);
		}
	}	

	else{
		if(wav.is16Bit()){
			return new SixteenBitMono(wav);
		}
		
		else{
			return new EightBitMono(wav);
		}
	}
	//wav.~Wav();
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}

wav_header Wav::getWaveHeader() {
	return waveHeader;
}

Wav::Wav(){}

Wav::Wav(const Wav& rhs){
	waveHeader = rhs.waveHeader;
	metadataVector = rhs.metadataVector;
}

bool Wav::isStereo() {
	if(waveHeader.num_channels == 2){
		return true;
	}

	else if(waveHeader.num_channels == 1){
		return false;
	}
}

bool Wav::is16Bit() {
	if(waveHeader.bit_depth == 16){
		return true;
	}

	else if(waveHeader.bit_depth == 8){
		return false;
	}
}

void Wav::makeCSV(){

	std::fstream fout;
	fout.open("audiofiles.csv", std::ios::out | std::ios::app);

	fout << "filename" << ", "
	     << "wav_size" << ", "
    	     << "fmt_chunk_size" << ", "
	     << "audio_format" << ", "
	     << "num_channels" << ", "
	     << "sample_rate" << ", "
	     << "byte_rate" << ", "
	     << "sample_alignment" << ", "
	     << "bit_depth" << ", "
	     << "data_bytes" << ", "
	     << " " << ", "
	     << "Metadata"
	     << "\n";

	fout.close();

}

void Wav::addToCSV(std::string filename){

	std::fstream fout;
	fout.open("audiofiles.csv", std::ios::out | std::ios::app);
	
    	fout << filename << ", "
	     << waveHeader.wav_size << ", "
    	     << waveHeader.fmt_chunk_size << ", "
	     << waveHeader.audio_format << ", "
	     << waveHeader.num_channels << ", "
	     << waveHeader.sample_rate << ", "
	     << waveHeader.byte_rate << ", "
	     << waveHeader.sample_alignment << ", "
	     << waveHeader.bit_depth << ", "
	     << waveHeader.data_bytes << ", "
	     << " " << ", "
	     << " " << ", ";
	     for(int i = 0; i < metadataVector.size(); i++){
		fout << metadataVector[i].metadata << ", ";
		//std::cout << "meta" << metadataVector[i].metadata << std::endl;
	     }
	fout << "\n";

	fout.close();
}

void Wav::editMetadata(){
	char header[4];
	std::string meta;

	std::cout << "Current Metadata: " << std::endl;
	for(int i = 0; i < metadataVector.size(); i++){
		std::cout << metadataVector[i].chunkheader
		  	  << metadataVector[i].metadata << std::endl;		  
	}

	std::cout << "Enter Metadata Chunk Header: ";
	std::cin >> header;
	std::cout << "Enter Metadata: ";
	std::cin >> meta;

	for(int i = 0; i < metadataVector.size(); i++){
		if(strcmp(header, metadataVector[i].chunkheader) == 0){
			metadataVector[i].metadata = meta;
			metadataVector[i].length = meta.length();
		}		  
	}
	
	Metadata newMetadata;
	for(int i=0; i < 4; i++){
		newMetadata.chunkheader[i] = header[i];
	}
	newMetadata.metadata = meta;
	newMetadata.length = meta.length();
	metadataVector.push_back(newMetadata);
}
