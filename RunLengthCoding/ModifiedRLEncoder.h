#ifndef MODIFIEDRLENCODER_H
#define MODIFIEDRLENCODER_H

#include<fstream>
#include<list>
#include<string>
#include"RunLengthEncoder.h"
using std::ifstream;
using std::ofstream;
using std::list;
using std::string;

class ModifiedRLEncoder : public RunLengthEncoder
{
protected:
	bool checkMSB(unsigned char);
public:
	ModifiedRLEncoder() {
		// repeatSymbolList.push_back(new RepeatSymbol);
	}
	void outputEncoded_mod(string);
};

#endif	// MODIFIEDRLENCODER