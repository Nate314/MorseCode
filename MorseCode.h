#include "BTNode.h"
#include "Binary_Tree.h"
#include "MorseDecoder.h"
#include "MorseEncoder.h"
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

#pragma once
class MorseCode {
private:
	// objects used for encoding and decoding
	MorseDecoder decoder;
	MorseEncoder encoder;
public:
	// populates the morse_code_tree
	MorseCode();
	// encodes a standard english word into morse code
	string encode(string str);
	// decode a string of morse code tokens into an english word
	string decode(string str);
};
