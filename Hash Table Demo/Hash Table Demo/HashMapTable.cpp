#include "HashMapTable.h"

using namespace std;

//Constructor
HashMapTable::HashMapTable()
{
	//Array of hash table entries
	ht = new HashTableEntry * [T_S];

	//Initialize records of array
	for (int i = 0; i < T_S; i++)
	{
		ht[i] = NULL;
	}
}

//HashFunc translates key value into index position
int HashMapTable::HashFunc(int key)
{
	return key % T_S;
}

//Insert new value into the hash table
void HashMapTable::Insert(int k, string v)
{
	//hash_v will become the index value
	int hash_v = HashFunc(k);

	//p is the previous entry, while en is the current entry
	HashTableEntry* p = NULL;
	HashTableEntry* en = ht[hash_v];

	//Check for open space
	while (en != NULL)
	{
		//Set previous equal to the entry
		p = en;

		//Set entry equal to the next entry
		en = en->n;
	}

	//Insert new table entry if the space is empty, 
	//else set the next value equal to the entry
	if (en == NULL)
	{
		en = new HashTableEntry(k, v);
		if (p == NULL)
		{
			ht[hash_v] = en;
		}
		else
		{
			p->n = en;
		}
	}
	else
	{
		en->v = v;
	}
}

//Search function
void HashMapTable::SearchKey(int k)
{
	//Hash_v will be the current value
	int hash_v = HashFunc(k);
	
	//Marks if the value is found or not
	bool flag = false;

	HashTableEntry* en = ht[hash_v];

	if (en != NULL)
	{
		while (en != NULL)
		{
			if (en->k == k)
			{
				flag = true;
			}

			if (flag)
			{
				cout << "Element was found at key " << k << ": ";
				cout << en->v << endl;
			}

			en = en->n;
		}
	}

	if (!flag)
	{
		cout << "Element not found with key " << k << "." << endl;
	}
}

//Deconstructor
HashMapTable::~HashMapTable()
{
	delete[] ht;
}

//Remove
void HashMapTable::Remove(int k)
{
	int hash_v = HashFunc(k);
	HashTableEntry* en = ht[hash_v];
	HashTableEntry* p = NULL;

	if (en == NULL || en->k != k)
	{
		cout << "No Element found at key " << k << endl;
		return;
	}

	while (en->n != NULL)
	{
		p = en;
		en = en->n;
	}

	if (p != NULL)
	{
		p->n = en->n;
	}

	delete en;
	cout << "Element Deleted." << endl;
}

