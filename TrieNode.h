#pragma once
#include "Tries.h"
class TrieNode
{
	Tries *root;

public:
	TrieNode() {
		root = new Tries('\0');
	}

private:

	void insertWord(Tries *root, string word) {
		// Base Case

		if (word.size() == 0) {
			root->isTerminal = true;
			return;
		}

		// Small Calculation

		int index = word[0] - 'a';
		Tries *child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new Tries(word[0]);
			root->children[index] = child;
		}

		// Recursive Call

		insertWord(child, word.substr(1));
	}

	bool searchWord(Tries *root, string word) {
		if (word.size() == 0) {
			return root->isTerminal;
		}

		int index = word[0] - 'a';
		Tries *child;

		if (root->children[index] != NULL) {
			child = root->children[index];
			if (child->data == word[0]) {
				return searchWord(child, word.substr(1));
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	void removeWord(Tries *root, string word) {
		if (word.size() == 0) {
			root->isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		Tries *child;

		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return;
		}

		removeWord(child, word.substr(1));

		if (child->isTerminal == false) {
			for (int i = 0; i < 26; i++) {
				if (child->children[index] != NULL) {
					return;
				}
			}
			delete child;
			root->children[index] = NULL;
		}
	}

public:

	void insertWord(string word) {
		insertWord(root, word);
	}

	bool searchWord(string word) {
		return searchWord(root, word);
	}

	void removeWord(string word) {
		removeWord(root, word);
	}
};

