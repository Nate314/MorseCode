#include "MorseCode.h"

// populates the morse_code_tree
MorseCode::MorseCode() {
	// temporary variables used in constructor
	Binary_Tree<std::pair<char, string>>
		temp(std::pair<char, string>('\n', ""),
			Binary_Tree<std::pair<char, string>>(),
			Binary_Tree<std::pair<char, string>>());
	string code;
	map<char, string> morse_codes;
	ifstream fin("dictionary.txt");
	char ch, current_char = NULL;
	// read each char in dictionary.txt
	while (fin >> ch) {
		// if ch is NOT a dot or a dash
		if (ch != MorseDecoder::DOT && ch != MorseDecoder::DASH) {
			// save code into map
			morse_codes.insert(std::pair<char, string>(current_char, code));
			// clear vars
			current_char = ch;
			code = "";
		}
		// if ch IS a dot or a dash
		else code += ch;
	}
	if (code != "") {
		morse_codes.insert(std::pair<char, string>(current_char, code));
	}
	// initialize map and tree objects
	encoder.initialize(morse_codes);
	decoder.initialize(morse_codes);
}

// encodes a standard english word into morse code
string MorseCode::encode(string str) {
	string encoded = "";
	istringstream tokens(str);
	char token;
	// for each char in the string to be encoded
	while (tokens >> token) {
		// add the encoded char to the result
		encoded += encoder.encode(token) + MorseDecoder::TOKEN_SEPARATOR;
	}
	// return the encoded string without the last space
	return encoded.substr(0, encoded.length() - 1);
}

// decode a string of morse code tokens into an english word
string MorseCode::decode(string str) {
	string decoded = "";
	istringstream tokens(str, MorseDecoder::TOKEN_SEPARATOR);
	string token;
	// for each token in the morse code string
	while (tokens >> token) {
		// add the decoded char to the result
		decoded += decoder.decode(token);
	}
	// return the decoded string
	return decoded;
}

template <class T>
bool has_root(Binary_Tree<T>& tree) {
	try {
		auto temp = tree.getRoot();
		if (temp == NULL) return false;
		else return true;
	}
	catch (exception ex) {
		return false;
	}
}