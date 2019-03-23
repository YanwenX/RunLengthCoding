#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include"RunLengthEncoder.h"
#include"RunLengthDecoder.h"
#include"ModifiedRLEncoder.h"
#include"ModifiedRLDecoder.h"
using namespace std;

int main()
{
	/*ifstream in_file;
	ofstream out_file("text_2.dat");
	list<RS> storeRepeat;
	char readNew;

	storeRepeat.push_back(new RepeatSymbol(0, '\0'));
	in_file.open("text.dat");
	while (in_file >> noskipws >> readNew) {
		if (storeRepeat.back()->value != readNew) {
			storeRepeat.push_back(new RepeatSymbol(1, readNew));
		}
		else if (storeRepeat.back()->value == readNew) {
			++storeRepeat.back()->count;
		}
	}
	
	in_file.close();

	for (list<RS>::iterator i = storeRepeat.begin(); i != storeRepeat.end(); ++i) {
		if ((*i)->value != '\0')
			out_file << unsigned char((*i)->count) << (*i)->value;
	}
	out_file.close();*/

	/*storeRepeat.clear();
	storeRepeat.push_back(new RepeatSymbol(0, '\0'));
	in_file.open("text_2.dat");
	int countRead = 0;
	while (in_file >> noskipws >> readNew) {
		if (countRead % 2 == 0) {
			storeRepeat.push_back(new RepeatSymbol(int(readNew), '\0'));
		}
		else {
			storeRepeat.back()->value = readNew;
		}
		++countRead;
	}

	in_file.close();

	for (list<RS>::iterator i = storeRepeat.begin(); i != storeRepeat.end(); ++i) {
		if ((*i)->value != '\0') {
			for (int j = 0; j < (*i)->count; ++j)
				cout << (*i)->value;
		}
	}
	cout << endl;*/

	RunLengthEncoder encoder_aud, encoder_bin, encoder_img, encoder_txt;
	RunLengthDecoder decoder_aud, decoder_bin, decoder_img, decoder_txt;

	ModifiedRLEncoder modEncoder_aud, modEncoder_bin, modEncoder_img, modEncoder_txt;
	ModifiedRLDecoder modDecoder_aud, modDecoder_bin, modDecoder_img, modDecoder_txt;

	string originalFile_aud = "audio.dat", originalFile_bin = "binary.dat",
		originalFile_img = "image.dat", originalFile_txt = "text.dat",
		encodedFile_aud = "audio_encoded.dat", encodedFile_bin = "binary_encoded.dat",
		encodedFile_img = "image_encoded.dat", encodedFile_txt = "text_encoded.dat",
		recoveredFile_aud = "audio_recover.dat", recoveredFile_bin = "binary_recovered.dat",
		recoveredFile_img = "image_recover.dat", recoveredFile_txt = "text_recovered.dat";

	string modEncoded_aud = "audio_modEncoded.dat", modEncoded_bin = "binary_modEncoded.dat",
		modEncoded_img = "image_modEncoded.dat", modEncoded_txt = "text_modEncoded.dat",
		modRecovered_aud = "audio_modRecover.dat", modRecovered_bin = "binary_modRecover.dat",
		modRecovered_img = "image_modRecover.dat", modRecovered_txt = "text_modRecover.dat";

	/* audio */
	encoder_aud.countRepeatSymbol(originalFile_aud);
	encoder_aud.outputEncodedFile(encodedFile_aud);

	decoder_aud.readEncodedFile(encodedFile_aud);
	decoder_aud.outputRecoveredFile(recoveredFile_aud);

	/* binary */
	/*encoder_bin.countRepeatSymbol(originalFile_bin);
	encoder_bin.outputEncodedFile(encodedFile_bin);

	decoder_bin.readEncodedFile(encodedFile_bin);
	decoder_bin.outputRecoveredFile(recoveredFile_bin);*/

	/* image */
	/*encoder_img.countRepeatSymbol(originalFile_img);
	encoder_img.outputEncodedFile(encodedFile_img);

	decoder_img.readEncodedFile(encodedFile_img);
	decoder_img.outputRecoveredFile(recoveredFile_img);*/

	/* text */
	/*encoder_txt.countRepeatSymbol(originalFile_txt);
	encoder_txt.outputEncodedFile(encodedFile_txt);

	decoder_txt.readEncodedFile(encodedFile_txt);
	decoder_txt.showEncodedFile();
	decoder_txt.outputRecoveredFile(recoveredFile_txt);*/

	/* audio */
	/*modEncoder_aud.countRepeatSymbol(originalFile_aud);
	modEncoder_aud.outputEncoded_mod(modEncoded_aud);

	modDecoder_aud.readEncoded(modEncoded_aud);
	modDecoder_aud.outputRecovered(modRecovered_aud);*/

	/* binary */
	/*modEncoder_bin.countRepeatSymbol(originalFile_bin);
	modEncoder_bin.outputEncoded_mod(modEncoded_bin);

	modDecoder_bin.readEncoded(modEncoded_bin);
	modDecoder_bin.outputRecovered(modRecovered_bin);*/

	/* image */
	/*modEncoder_img.countRepeatSymbol(originalFile_img);
	modEncoder_img.outputEncoded_mod(modEncoded_img);

	modDecoder_img.readEncoded(modEncoded_img);
	modDecoder_img.outputRecovered(modRecovered_img);*/

	/* text */
	/*modEncoder_txt.countRepeatSymbol(originalFile_txt);
	modEncoder_txt.outputEncoded_mod(modEncoded_txt);

	modDecoder_txt.readEncoded(modEncoded_txt);
	modDecoder_txt.outputRecovered(modRecovered_txt);*/
		
	return 0;
}