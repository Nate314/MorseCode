#include "MorseCode.h"
#include "BTNode.h"

const char MorseCode::DOT = '.';
const char MorseCode::DASH = '_';

void load_tree(Binary_Tree<std::pair<char, string>>& tree, map<char, string>& codes, int len) {
	string parent_val = tree.getRoot()->data.second;
	for (std::pair<char, string> code : codes) {
		string current_val = code.second;
		if (current_val.length() == len && current_val.find(parent_val) == 0) {
			if (current_val[current_val.length() - 1] == MorseCode::DOT) {
				BTNode<std::pair<char, string>>* new_node = new BTNode<std::pair<char, string>>(code);
				tree.getRoot()->left = new_node;
				codes.erase(code.first);
				Binary_Tree<std::pair<char, string>> temp = tree.get_left_subtree();
				load_tree(tree, codes, len);
				load_tree(temp, codes, len + 1);
				break;
			}
			else if (current_val[current_val.length() - 1] == MorseCode::DASH) {
				BTNode<std::pair<char, string>>* new_node = new BTNode<std::pair<char, string>>(code);
				tree.getRoot()->right = new_node;
				codes.erase(code.first);
				Binary_Tree<std::pair<char, string>> temp = tree.get_right_subtree();
				load_tree(tree, codes, len);
				load_tree(temp, codes, len + 1);
				break;
			}
		}
	}
}

MorseCode::MorseCode() {
	map<char, string> morse_codes;
	ifstream fin("dictionary.txt");
	char last_char = NULL;
	char current_char = NULL;
	string morse_code;
	char ch;
	while (fin >> ch) {
		if (ch != DOT && ch != DASH) {
			morse_codes.insert(std::pair<char, string>(current_char, morse_code));
			last_char = current_char;
			current_char = ch;
			morse_code = "";
		}
		else morse_code += ch;
	}
	Binary_Tree<std::pair<char, string>> temp(std::pair<char, string>('_', ""), Binary_Tree<std::pair<char, string>>(), Binary_Tree<std::pair<char, string>>());
	load_tree(temp, morse_codes, 1);
	morse_code_tree = temp;
	cout << "done" << endl;
}

MorseCode::~MorseCode() {

}

string MorseCode::encode(string str) {
	return str;
}

string MorseCode::decode(string str) {
	return str;
}
