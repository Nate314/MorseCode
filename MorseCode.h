#include "Binary_Tree.h"
#include "Binary_Search_Tree.h"
#include<map>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

#pragma once
class MorseCode {
private:
	Binary_Tree<std::pair<char, string>> morse_code_tree;
public:
	static const char DOT;
	static const char DASH;
	MorseCode();
	~MorseCode();
	string encode(string str);
	string decode(string str);
};
