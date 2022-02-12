#pragma once
#include "HashTableEntry.h"

using namespace std;


//Table size
const int T_S = 200;

class HashMapTable
{
public:
	//ht stands for Hash Table
	HashTableEntry** ht;
	HashTableEntry** top;

	//Constructor
	HashMapTable();

	//Functions
	int HashFunc(int key);
	void Insert(int k, string v);
	void SearchKey(int k);
	void Remove(int k);

	//Deconstructor
	~HashMapTable();
};
