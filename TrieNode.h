#pragma once
#include "Tries.h"
class TrieNode
{
	Tries *root;

	void insertWord(Tries *root, string word) {
		if (word.size() == 0) {
			root->isTerminal = true;
			return;
		}

		int index = word[0] - 'a';
		Tries *child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new Tries(word[0]);
		}
	}

public:
	TrieNode() {
		root = new Tries('\0');
	}

	void insertWord(string word) {
		insertWord(root, word);
	}
};

