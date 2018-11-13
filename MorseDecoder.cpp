#include "MorseDecoder.h"

// inserts a char into the tree by the specified path
Binary_Tree<char> insert(Binary_Tree<char> tree, string code, char ch, bool& added) {
	if (code.size() > 0) {
		char dir = code[0];
		if (tree.getRoot() == nullptr) tree.setRoot(new BTNode<char>('\n'));
		if (dir == MorseDecoder::DOT)
			return Binary_Tree<char>(tree.getRoot()->data,
				insert(tree.get_left_subtree(), code.substr(1, code.size() - 1), ch, added),
				tree.get_right_subtree());
		else if (dir == MorseDecoder::DASH)
			return Binary_Tree<char>(tree.getRoot()->data,
				tree.get_left_subtree(),
				insert(tree.get_right_subtree(), code.substr(1, code.size() - 1), ch, added));
	}
	if (!added) {
		try {
			return Binary_Tree<char>(ch, tree.get_left_subtree(), tree.get_right_subtree());
		}
		catch (std::exception e) {
			return Binary_Tree<char>(ch, Binary_Tree<char>('\n'), Binary_Tree<char>('\n'));
		}
	}
	added = true;
}

// blank constructor
MorseDecoder::MorseDecoder() {

}

// loads the map of codes in to this class as a tree
void MorseDecoder::initialize(map<char, string> morse_code_map) {
	Binary_Tree<char> left = Binary_Tree<char>('\n');
	Binary_Tree<char> right = Binary_Tree<char>('\n');
	my_tree = Binary_Tree<char>('\n', left, right);
	for (std::pair<char, string> item : morse_code_map) {
		bool temp = false;
		my_tree = insert(my_tree, item.second, item.first, temp);
	}
}

// returns the decoded char associated with the string passed
char MorseDecoder::decode(string str) {
	try {
		char result = '?';
		Binary_Tree<char> tree = my_tree;
		for (char token : str) {
			if (token == '.') tree = tree.get_left_subtree();
			else if (token == '_') tree = tree.get_right_subtree();
		}
		result = tree.getRoot()->data;
		if (result == '\n' || result == '\0') result = '?';
		return result;
	}
	catch (std::exception e) {
		return '?';
	}
}
