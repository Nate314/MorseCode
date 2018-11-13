#include "MorseEncoder.h"

// blank constructor
MorseEncoder::MorseEncoder() {

}

// loads the map of codes in to this class
void MorseEncoder::initialize(map<char, string> morse_code_map) {
	for (std::pair<char, string> item : morse_code_map) my_map.insert(item);
}

// returns the encoded string associated with the char passed
string MorseEncoder::encode(char ch) {
	if (my_map.count(ch) != 0) {
		return my_map[ch];
	}
	else {
		return "N/A";
	}
}
