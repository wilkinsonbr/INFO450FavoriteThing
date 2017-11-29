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
	cout << endl;
	ifstream infile(saveWhere);

	if (infile.good())
	{
		while (!infile.eof())
		{
			string author, title, length, genre;
			getline(infile, author, '|');

			if (author.length())
			{
				getline(infile, title, '|');
				getline(infile, length, '|');
				getline(infile, genre, '\n');

				booklist[count] = new Book(author, title, length, genre);
				count++;
			}
		}
	}

	cout << "Do you have any favorite books? Y/N" << endl;
	cin >> addMore;
	cin.ignore();
	cin.clear();

	while (addMore == 'y' || addMore == 'Y')
	{
		booklist[count] = new Book();
		if (booklist[count]->input() == 0)
		{
			count++;

		}

		cout << "Add another book to your favorites (Y/N)" << endl;
		cin >> addMore;
		cout << endl;
	}
		for (i = 0; i < count; i++)
		{
			booklist[i]->output();
		}

		ofstream outfile(saveWhere);

		if (!outfile.good()) {
			cout << "No File Found" << endl;
			return -1;
		}

		for (i = 0; i < count; i++)
		{
			outfile << booklist[i];
		}

		for (i = 0; i < count; i++)
		{
			delete booklist[i];
		}



	
	return 0;
	delete booklist;
}

