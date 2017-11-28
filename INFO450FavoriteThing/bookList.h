#pragma once
#include <string>
#include "stdafx.h"
#include <iostream>
#include "Book.h"
using namespace std;

class BookList
{
private:
	Book **list;
	int lSize;

public:
	BookList();
	~BookList();
	void displayBook;
	int saveBook(string filename);
	int findBook(string filename);
};

