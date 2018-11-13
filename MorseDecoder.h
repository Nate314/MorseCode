#include "Binary_Tree.h"
#include<map>
using namespace std;

#pragma once
class MorseDecoder {
private:
	// stores letters for decoding
	Binary_Tree<char> my_tree;
public:
	// blank constructor
	MorseDecoder();
	// loads the map of codes in to this class as a tree
	void initialize(map<char, string> morse_code_map);
	// returns the decoded char associated with the string passed
	char decode(string);
	// static chars
	static const char DOT = '.';
	static const char DASH = '_';
	static const char TOKEN_SEPARATOR = ' ';
};
