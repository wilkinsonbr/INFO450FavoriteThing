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

Book::~Book()
{}

int Book::input()
{

	cout << "Please enter the following information on your favorite book" << endl;
	cout << "Example Author: Koontz, Title: The Silent Corner, Length: 433, Genre: Mystery" << endl;
	cout << endl;
	cout << "Who is the author?" << endl;
	cin >> author;
	cout << "What is the Title?" << endl;
	cin >> title;
	cout << "How many pages is it?" << endl;
	cin >> length;
	cout << "What genre is it?" << endl;
	cin >> genre;

	return 0;
}

void Book::output()
{
	cout << "The book " << title << " written by " << author
		<< " is " << length << " long, and is a " 
		<< genre << " novel." << endl;
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
		return 1;
	}
	
	return 0;
}