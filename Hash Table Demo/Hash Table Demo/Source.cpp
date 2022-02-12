#include <iostream>
#include <string>
#include "HashMapTable.h"

using namespace std;

int main()
{
	HashMapTable hash;
	int k;
	string v;
	int c;

	while (1)
	{
		cout << "1.) Insert an element into the table." << endl;
		cout << "2.) Search an element by the value." << endl;
		cout << "3.) Delete an element by it's value." << endl;
		cout << "4.) Exit." << endl;
		cout << "Enter your choice: ";
		cin >> c;

		switch (c)
		{
		case 1:
			cout << "Eneter element to be inserted: ";
			cin >> k;
			hash.Insert(k, v);
			break;
		case 2:
			cout << "Enter value of the element to be searched: ";
			cin >> k;
			hash.SearchKey(k);
			break;
		case 3:
			cout << "Enter value of the element to be deleted: ";
			cin >> k;
			hash.Remove(k);
			break;
		case 4:
			exit(1);
			break;
		default:
			cout << "\nEnter corrent option.\n";
		}
	}

	return 0;
}