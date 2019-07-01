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
		isTerminal = false;
	}
};

