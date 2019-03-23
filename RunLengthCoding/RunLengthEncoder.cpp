#include"RunLengthEncoder.h"
#include<fstream>
using std::ios;
using std::noskipws;

void RunLengthEncoder::countRepeatSymbol(string fileName)
{
	inFile.open(fileName, ios::binary);
	unsigned char readNext;
	while (inFile >> noskipws >> readNext) {
		if (repeatSymbolList.back()->value != readNext ||
			repeatSymbolList.back()->isHead) {
			repeatSymbolList.push_back(new RepeatSymbol(1, readNext, false));
		}
		else {
			++repeatSymbolList.back()->countRepeat;
		}
	}
	inFile.close();
}

void RunLengthEncoder::outputEncodedFile(string fileName)
{
	outFile.open(fileName, ios::binary);
	for (list<RS>::iterator i = repeatSymbolList.begin(); i != repeatSymbolList.end(); ++i) {
		if (!(*i)->isHead) {
			if ((*i)->countRepeat > 255) {
				for (long j = 1; j <= (*i)->countRepeat; ++j) {
					if (j % 255 == 0 && j != (*i)->countRepeat)
						outFile << unsigned char(255) << (*i)->value;
					else if (j % 255 != 0 && j == (*i)->countRepeat)
						outFile << unsigned char(j % 255) << (*i)->value;
				}
			}
			else
				outFile << unsigned char((*i)->countRepeat) << (*i)->value;
		}
	}
	outFile.close();
}