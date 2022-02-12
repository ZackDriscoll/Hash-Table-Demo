#pragma once
#include <iostream>
#include <string>

using namespace std;

struct HashTableEntry
{
	//K represents the key, and v is the data stored
	int k;
	string v;

	//n stands for "next" in this instance
	HashTableEntry* n;

	//Constructor
	HashTableEntry(int k, string v)
	{
		this->k = k;
		this->v = v;
		this->n = NULL;
	}
};