#include "BTNode.h"
#include "Binary_Tree.h"
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

#pragma once
class MorseCode {
private:
	// contains the morse codes for the english alphabet
	Binary_Tree<std::pair<char, string>> morse_code_tree;
	// returns the morse code for the specified english char
	string encode_char(char ch);
	// returns the english char for the specified morse code
	char decode_char(string str);
public:
	// populates the morse_code_tree
	MorseCode();
	// encodes a standard english word into morse code
	string encode(string str);
	// decode a string of morse code tokens into an english word
	string decode(string str);
	// dot and dash
	static const char DOT;
	static const char DASH;
};
