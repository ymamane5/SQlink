#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include "memManager.h"
#include "memPool.h"
#include "memPage.h"


using namespace std;

int main()
{
	int input;
	unsigned int num, len;
	string str;
	char buff[16];

	cout << "Enter defualt page size or 0 to use 16\n";
	cin >> num;
	if (num != 0)
		memManager::setPageSize(num);

	memPage page;
	memPool pool;


	do {
		cout << "choose option:\n1. write to pool\n2. write to pool at position\n3. read from pool\n";
		cout << "4. read from pool at position\n5. set current position\n6. get actual size\n7. get page size\n8. Exit\n";
		cin >> input;
		
		switch (input)
		{
		case 1:
			cout << "Enter string to insert:\n";
			cin >> str;
			cout << "Enter length\n";
			cin >> len;
			cout << pool.writeData(str.c_str(), len) << " characters has been written\n";
			break;
		case 2:
			cout << "Enter string to insert:\n";
			cin >> str;
			cout << "Enter length\n";
			cin >> len;
			cout << "Enter position\n";
			cin >> num;
			cout << pool.writeData(str.c_str(), len, num) << " characters has been written\n";
			break;
		case 3:
			cout << "Enter length to read\n";
			cin >> len;
			cout << "read " << pool.readData(buff, len) << " characters\n";
			cout << "string = " << buff << "\n";
			break;
		case 4:
			cout << "Enter length to read\n";
			cin >> len;
			cout << "Enter position\n";
			cin >> num;
			cout << "read " << pool.readData(buff, num, len) << " characters\n";
			cout << "string = " << buff << "\n";
			break;
		case 5:
			cout << "Enter new current position\n";
			cin >> num;
			try 
			{
				pool.setCurrPosition(num);
			}
			catch(int e)
			{
				cout << e << ": cannot change current position\n";
			}	
			cout << "currunt position changed\n";

			cout << "new current position = " << pool.getCurrPosition() << "\n";
			break;
		case 6:
			cout << "actual size = " << pool.actualSize() << "\n";
			break;
		case 7:
			cout << "page size = " << pool.getPageSize() << "\n";
			cout << "defualt page size = " << memPool::getDefPageSize() << "\n";
			break;
		default:
			break;
		}
		
	} while (input < 8);
	
	getchar();
	return 0;

}