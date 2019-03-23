#ifndef RUNLENGTHDECODER_H
#define RUNLENGTHDECODER_H

#include"RunLengthEncoder.h"
#include<fstream>
#include<list>
#include<string>
using std::ifstream;
using std::ofstream;
using std::list;
using std::string;

class RunLengthDecoder : public RunLengthEncoder
{
private:

public:
	RunLengthDecoder() {
		// repeatSymbolList.push_back(new RepeatSymbol(0, '\0', 1));
	}
	void readEncodedFile(string);
	void showEncodedFile();
	void outputRecoveredFile(string);
};



#endif	// RUNLENGTHDECODER_H
