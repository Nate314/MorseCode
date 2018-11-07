#include "MorseCode.h"

// dot and dash
const char MorseCode::DOT  = '.';
const char MorseCode::DASH = '_';

// loads the binary tree from a map of morse code values
void load_tree(Binary_Tree<std::pair<char, string>>& tree, map<char, string>& codes, int len) {
	// morse code value of parent
	string parent_val = tree.getRoot()->data.second;
	for (std::pair<char, string> code : codes) {
		// morse code value of current code iteration
		string current_val = code.second;
		// if the current value's length matches len
		// AND
		// the current value starts with the parent value
		if (current_val.length() == len && current_val.find(parent_val) == 0) {
			// if the current value's last value is a dot
			if (current_val[current_val.length() - 1] == MorseCode::DOT) {
				// set the left node of this tree to the current code
				// and remove the current code from the map
				BTNode<std::pair<char, string>>* new_node = new BTNode<std::pair<char, string>>(code);
				tree.getRoot()->left = new_node;
				codes.erase(code.first);
				// recursive calls
				Binary_Tree<std::pair<char, string>> temp = tree.get_left_subtree();
				load_tree(tree, codes, len);
				load_tree(temp, codes, len + 1);
				break;
			}
			// if the current value's last value is a dash
			else if (current_val[current_val.length() - 1] == MorseCode::DASH) {
				// set the left node of this tree to the current code
				// and remove the current code from the map
				BTNode<std::pair<char, string>>* new_node = new BTNode<std::pair<char, string>>(code);
				tree.getRoot()->right = new_node;
				codes.erase(code.first);
				Binary_Tree<std::pair<char, string>> temp = tree.get_right_subtree();
				// recursive calls
				load_tree(tree, codes, len);
				load_tree(temp, codes, len + 1);
				break;
			}
		}
	}
}

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
		if (ch != DOT && ch != DASH) {
			// save code into map
			morse_codes.insert(std::pair<char, string>(current_char, code));
			// clear vars
			current_char = ch;
			code = "";
		}
		// if ch IS a dot or a dash
		else code += ch;
	}
	// load tree from map
	load_tree(temp, morse_codes, 1);
	morse_code_tree = temp;
}

// encodes a standard english word into morse code
string MorseCode::encode(string str) {
	string encoded = "";
	istringstream tokens(str);
	char token;
	// for each char in the string to be encoded
	while (tokens >> token) {
		// add the encoded char to the result
		encoded += encode_char(token) + " ";
	}
	// return the encoded string without the last space
	return encoded.substr(0, encoded.length() - 1);
}

// decode a string of morse code tokens into an english word
string MorseCode::decode(string str) {
	string decoded = "";
	istringstream tokens(str);
	string token;
	// for each token in the morse code string
	while (tokens >> token) {
		// add the decoded char to the result
		decoded += decode_char(token);
	}
	// return the decoded string
	return decoded;
}

// returns the english char for the specified morse code
char MorseCode::decode_char(string str) {

}

// returns the morse code for the specified english char
string MorseCode::encode_char(char ch) {

}
