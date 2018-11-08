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

// returns the first pair found in the passed tree with the first value of the passed target
//  search_for_char ? search for char_target : search for str_target.
std::pair<char, string> MorseCode::search_tree(Binary_Tree<std::pair<char, string>>& tree, char& char_target, string& str_target, bool& search_for_char) {
	// if the root of this tree is null or nonexitant
	if (!has_root(tree)) return null_pair;
	// if the data in the root matches the target being searched for return root->data
	else if ((search_for_char && tree.getRoot()->data.first == char_target)
		|| (!search_for_char && tree.getRoot()->data.second == str_target))
		return tree.getRoot()->data;
	// else recursively call
	else {
		Binary_Tree<std::pair<char, string>> left = tree.get_left_subtree();
		Binary_Tree<std::pair<char, string>> right = tree.get_right_subtree();
		std::pair<char, string> left_result = null_pair;
		std::pair<char, string> right_result = null_pair;
		// if the left is not null search left subtree
		if (has_root(left)) left_result = search_tree(left, char_target, str_target, search_for_char);
		// if the value was not found on the left and the right is not null search right subtree
		if (left_result == null_pair && has_root(right)) right_result = search_tree(right, char_target, str_target, search_for_char);
		// return left_result if that is where the target was found
		if (left_result != null_pair) return left_result;
		// otherwise return right_result
		else return right_result;
	}
}

// returns the english char for the specified morse code
char MorseCode::decode_char(string str) {
	char dummy = '?';
	bool search_for_char = false;
	return search_tree(morse_code_tree, dummy, str, search_for_char).first;
}

// returns the morse code for the specified english char
string MorseCode::encode_char(char ch) {
	string dummy = "N/A";
	bool search_for_char = true;
	return search_tree(morse_code_tree, ch, dummy, search_for_char).second;
}
