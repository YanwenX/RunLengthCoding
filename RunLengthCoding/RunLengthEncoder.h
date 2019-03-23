#ifndef RUNLENGTHENCODER_H
#define RUNLENGTHENCODER_H

#include<fstream>
#include<list>
#include<string>
using std::ifstream;
using std::ofstream;
using std::list;
using std::string;

typedef struct RepeatSymbol {
	long countRepeat;
	unsigned char value;
	bool isHead;
	RepeatSymbol() : countRepeat(0), value('\0'), isHead(1) {}
	RepeatSymbol(long c, unsigned char v, bool h) : countRepeat(c), value(v), isHead(h) {}
}*RS;

class RunLengthEncoder
{
protected:
	ifstream inFile;
	ofstream outFile;
	list<RS> repeatSymbolList;
public:
	RunLengthEncoder() {
		repeatSymbolList.push_back(new RepeatSymbol(0, '\0', 1));
	}
	void countRepeatSymbol(string);
	void outputEncodedFile(string);
};


#endif	// RUNLENGTHENCODER_H
