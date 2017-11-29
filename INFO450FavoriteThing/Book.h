#pragma once
#include <string>
#include "stdafx.h"
#include <iostream>
using namespace std;

class Book
{
private:
	string author;
	string title;
	string length;
	string genre;


public:
	Book();
	Book(string auth, string tl, string len, string gen);
	~Book();

	int input();
	int output();

	friend ofstream& operator<<(ofstream &fs, Book *item);
	friend bool operator ==(Book& original, Book& duplicate);

};

