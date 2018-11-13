#include<map>
#include<iostream>
using namespace std;

#pragma once
class MorseEncoder {
private:
	// stores codes for encoding
	map<char, string> my_map;
public:
	// blank constructor
	MorseEncoder();
	// loads the map of codes in to this class
	void initialize(map<char, string> morse_code_map);
	// returns the encoded string associated with the char passed
	string encode(char ch);
};
