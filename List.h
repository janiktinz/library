#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#pragma once
class List
{
	public:
		List();
		~List();

		void print();
		void insert_head(Book*);
		void insert_tail(Book*);
		void delete_book(Book*);
		Book* search(unsigned int);
		void merge_sort();
		Book *merge(Book*, Book*);
		Book *divide(Book*);
		void swap(Book*, Book*);

	private:
		Book *merge_sort(Book*);
		Book *head = NULL;
		Book *tail = NULL;
};