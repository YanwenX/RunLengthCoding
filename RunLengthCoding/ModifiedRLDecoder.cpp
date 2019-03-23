#include"ModifiedRLDecoder.h"
using std::ios;
using std::noskipws;

void ModifiedRLDecoder::readEncoded(string fileName)
{
	inFile.open(fileName, ios::binary);
	unsigned char readNext;
	list<unsigned char> symbolList;
	while (inFile >> noskipws >> readNext) {
		symbolList.push_back(readNext);
	}

	while (!symbolList.empty()) {
		unsigned char tempSymbol = symbolList.front();
		if (int(tempSymbol) > 128) {
			repeatSymbolList.push_back(new RepeatSymbol(long(tempSymbol) - 128, '\0', false));
			symbolList.pop_front();
			tempSymbol = symbolList.front();
			repeatSymbolList.back()->value = tempSymbol;
			symbolList.pop_front();
		}
		else {
			repeatSymbolList.push_back(new RepeatSymbol(1, tempSymbol, false));
			symbolList.pop_front();
		}
	}
	inFile.close();
}

void ModifiedRLDecoder::outputRecovered(string fileName)
{
	outFile.open(fileName, ios::binary);
	for (list<RS>::iterator i = repeatSymbolList.begin(); i != repeatSymbolList.end(); ++i) {
		if (!(*i)->isHead) {
			for (long j = 0; j < (*i)->countRepeat; ++j)
				outFile << (*i)->value;
		}
	}
}