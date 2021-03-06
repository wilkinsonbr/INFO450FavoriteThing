#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

Book::Book()
{
	author = "";
	title = "";
	length = "";
	genre = "";
	

}

Book::Book(string auth, string tl, string len, string gen)
{
	author = auth;
	title = tl;
	length = len;
	genre = gen;

}


int Book::input()
{

	cout << "Please enter the following information on your favorite book" << endl;
	cout << endl;
	cout << "Example Author: Koontz, Title: The Silent Corner, Length: 433, Genre: Mystery" << endl;
	cout << endl;
	cout << endl;
	cout << "Who is the author?" << endl;
	getline(cin, author);
	cout << "What is the Title?" << endl;
	getline(cin, title);
	cout << "How many pages is it?" << endl;
	getline(cin, length);
	cout << "What genre is it?" << endl;
	getline(cin, genre);


	return 0;
}

int Book::output()
{
	cout << "The book " << title << " written by " << author
		<< " is " << length << " pages long, and is a " 
		<< genre << " novel." << endl;
	cout << endl;
	return 0;
}

ofstream& operator<<(ofstream &fs, Book *item)
{
	fs << item->author << " " << item->title << " " << item->length << " " << item->genre << endl;
	return fs;
}

bool operator ==(Book &original, Book &duplicate)
{
	
	if (original == duplicate)
	{
		cout << "You have entered the same item twice" << endl;
		return -1;
	}
	
}
Book::~Book()
{}