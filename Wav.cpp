#include <string>
#include <fstream>
#include <iostream>
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
        file.close();

	std::cout << 1 << std::endl;
    }
}

unsigned char *Wav::getBuffer() const{
    return buffer;
}

short *Wav::getShortBuffer() const{
    short* shortBuffer = reinterpret_cast<short*>(buffer);
    return shortBuffer;
}

void Wav::writeFile(const std::string &outFileName) {
    if(Wav::isStereo()){
	if(Wav::is16Bit()){
	}

	else{
	}
    }

    else{
	if(Wav::is16Bit()){
	}

	else{
   	 	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
   	 	outFile.write((char*)&waveHeader,sizeof(wav_header));
    		outFile.write((char*)buffer, waveHeader.data_bytes);
    		outFile.close();
	}
    }
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
	std::cout << "hey 1" << std::endl;
	waveHeader = rhs.waveHeader;
	std::cout << "hey 2" << std::endl;
	buffer = rhs.buffer;
	std::cout << "hey 3" << std::endl;
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

void Wav::makeCSV(std::vector<std::string> files){

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
	     << "data_bytes"
	     << "\n";

	for(int i=0; i < files.size(); i++){
		
    	fout << files[i] << ", "
	     << waveHeader.wav_size << ", "
    	     << waveHeader.fmt_chunk_size << ", "
	     << waveHeader.audio_format << ", "
	     << waveHeader.num_channels << ", "
	     << waveHeader.sample_rate << ", "
	     << waveHeader.byte_rate << ", "
	     << waveHeader.sample_alignment << ", "
	     << waveHeader.bit_depth << ", "
	     << waveHeader.data_bytes
	     << "\n";
	}

}

