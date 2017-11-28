// INFO450FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Book.h"
#include <string>
using namespace std;

int LIST = 100;


int main()
{
	Book **booklist;
	int count = 0;
	int i;
	string saveWhere;
	char addMore;
	
	booklist = new Book*[LIST];

	cout << "Where would you like your file saved?" << endl;
	getline(cin, saveWhere);
	ifstream infile(saveWhere);

	if (infile.good())
	{
		while (!infile.eof())
		{
			string author, title, length, genre;
			getline(infile, title, '|');
			
			if (title.length())
			{
				getline(infile, author, '|');
				getline(infile, length,'|');
				getline(infile, genre, '|');

				booklist[count] = new Book(stoi(title), author, length, genre);
				count++;
			}
		}
	}

    return 0;
}

