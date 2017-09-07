#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#pragma once
class Book
{
	public:
		void print();
		void edit();

		// getter and setter methods
		void setPrev(Book* prev);
		Book* getPrev() const;
		void setNext(Book* next);
		Book* getNext() const;
		void setTitle(string);
		string getTitle() const;
		void setPublisher(string);
		string getPublisher() const;
		void setYear(int);
		int getYear() const;
		void setAuthor(string);
		string getAuthor() const;
		void setIsbn_number(unsigned int);
		unsigned int getIsbn_number() const;

	private:
		Book *next = NULL;
		Book *prev = NULL;

		string author;
		string title;
		int year = 0;
		string publisher;
		unsigned int isbn_number = 0;
};