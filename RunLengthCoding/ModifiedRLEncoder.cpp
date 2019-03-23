#include"ModifiedRLEncoder.h"
#include<fstream>
using std::ios;
using std::noskipws;

bool ModifiedRLEncoder::checkMSB(unsigned char ch)
{
	return (int(ch) >= 128);
}

void ModifiedRLEncoder::outputEncoded_mod(string fileName)
{
	outFile.open(fileName, ios::binary);
	for (list<RS>::iterator i = repeatSymbolList.begin(); i != repeatSymbolList.end(); ++i) {
		if (!(*i)->isHead) {
			if ((*i)->countRepeat == 1) {
				if (!checkMSB((*i)->value))
					outFile << (*i)->value;
				else {
					int specialCountOne = 129;
					outFile << unsigned char(specialCountOne) << (*i)->value;
				}
			}
			else if ((*i)->countRepeat > 127) {
				for (long j = 1; j <= (*i)->countRepeat; ++j) {
					if (j % 127 == 0 && j != (*i)->countRepeat) {
						int specialCount127 = 255;
						outFile << unsigned char(specialCount127) << (*i)->value;
					}
					else if (j % 127 != 0 && j == (*i)->countRepeat)
						outFile << unsigned char(128 + j % 127) << (*i)->value;
				}
			}
			else
				outFile << unsigned char(128 + (*i)->countRepeat) << (*i)->value;
		}
	}
	outFile.close();
}