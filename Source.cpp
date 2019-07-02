#include <iostream>
#include "TrieNode.h"
using namespace std;

int main() {
	cout << "Hello World" << endl;
	TrieNode t;

	t.insertWord("hello");
	t.insertWord("byr");
	cout << t.searchWord("hello") << endl;
	cout << t.searchWord("byr") << endl;
	t.removeWord("hello");
	cout << t.searchWord("hello");
}