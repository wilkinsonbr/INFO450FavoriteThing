// INFO450FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Book.h"
#include <string>
using namespace std;

const int LIST = 100;


int main()
{
	Book **booklist;
	int count = 0;
	int i;
	string saveWhere;
	char addMore = 'y';
	
	booklist = new Book*[LIST];

	cout << "Where would you like your file saved?" << endl;
	getline(cin, saveWhere);
	ifstream infile(saveWhere);

	if (infile.good())
	{
		while (!infile.eof())
		{
			string author, title, length, genre;
			getline(infile, title, ',');
			
			if (title.length())
			{
				getline(infile, author, '|');
				getline(infile, length,'|');
				getline(infile, genre, '|');

				booklist[count] = new Book(title, author, length, genre);
				count++;
			}
		}
	}

	while (addMore == 'y' || addMore == 'Y')
	{
		booklist[count] = new Book();
		if (booklist[count]->input() == 0) {
			count++;

			cout << "Do you have any other favorite books? Y/N" << endl;
			cin >> addMore;
		}
			
		ofstream outfile(saveWhere);
		if (!outfile.good()) {
			cout << "No File Found" << endl;
			return -1;
		}
	
		for (i = 0; i < LIST; i++)
		{
			outfile << booklist[i];
		}

		for (i = 0; i < LIST; i++)
		{
			delete booklist[i];
		}

	}


    return 0;
}

