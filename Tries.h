#pragma once
#include <iostream>
using namespace std;

class Tries
{
public:
	char data;
	Tries **children;
	bool isTerminal;

	Tries(char data) {
		this->data = data;
		Tries **children = new Tries*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

