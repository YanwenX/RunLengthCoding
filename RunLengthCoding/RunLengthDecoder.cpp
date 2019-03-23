#include"RunLengthEncoder.h"
#include"RunLengthDecoder.h"
#include<iostream>
using std::ios;
using std::noskipws;
using std::cout;
using std::endl;

void RunLengthDecoder::readEncodedFile(string fileName)
{
	inFile.open(fileName, ios::binary);
	unsigned char readNext;
	long countRead = 0;
	while (inFile >> noskipws >> readNext) {
		if (countRead % 2 == 0) {
			repeatSymbolList.push_back(new RepeatSymbol(long(readNext), '\0', false));
		}
		else {
			repeatSymbolList.back()->value = readNext;
		}
		++countRead;
	}
	inFile.close();
}

void RunLengthDecoder::showEncodedFile()
{
	for (list<RS>::iterator i = repeatSymbolList.begin(); i != repeatSymbolList.end(); ++i) {
		if (!(*i)->isHead) {
			for (long j = 0; j < (*i)->countRepeat; ++j)
				cout << (*i)->value;
		}
	}
	cout << endl;
}

void RunLengthDecoder::outputRecoveredFile(string fileName)
{
	outFile.open(fileName, ios::binary);
	for (list<RS>::iterator i = repeatSymbolList.begin(); i != repeatSymbolList.end(); ++i) {
		if (!(*i)->isHead) {
			for (long j = 0; j < (*i)->countRepeat; ++j)
				outFile << (*i)->value;
		}
	}
	outFile.close();
}