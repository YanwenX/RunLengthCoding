#ifndef MODIFIEDRLDECODER_H
#define MODIFIEDRLDECODER_H

#include"ModifiedRLEncoder.h"
#include<string>
using std::string;

class ModifiedRLDecoder : public ModifiedRLEncoder
{
private:

public:
	ModifiedRLDecoder() {}
	void readEncoded(string);
	void outputRecovered(string);
};

#endif	// MODIFIEDRLDECODER_H
