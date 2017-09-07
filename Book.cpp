#include "Book.h"
using namespace std;

void Book::print()
{
	// Output of a book
	cout << "Buch: " << endl;
	cout << "Autor...........: " << author << endl;
	cout << "Titel...........: " << title << endl;
	cout << "Erscheinungsjahr: " << year << endl;
	cout << "Verlag..........: " << publisher << endl;
	cout << "ISBN............: " << isbn_number << endl;
	cout << endl;
}

void Book::edit()
{
	// edit a book
	cout << "Buch: " << endl;
	string tmp = "";
	cout << "Autor...........: ";
	cin.ignore();
	getline(cin, tmp);
	if (tmp != "")
		author = tmp;
	cout << "Titel...........: ";
	getline(cin, tmp);
	if (tmp != "")
		title = tmp;
	cout << "Erscheinungsjahr: ";
	getline(cin, tmp);
	if (tmp != "")
		year = atoi(tmp.c_str());   
	cout << "Verlag..........: ";
	getline(cin, tmp);
	if (tmp != "")
		publisher = tmp;
	cout << "ISBN............: ";
	getline(cin, tmp);
	if (tmp != "")
		isbn_number = atoi(tmp.c_str());
	cout << endl;
	cout << "- Enter druecken, um fortzufahren... -";
	cin.ignore();
	cout << endl;
}

void Book::setPrev(Book* prev) {
	this->prev = prev;
}

Book* Book::getPrev() const {
	return prev;
}

void Book::setNext(Book* next) {
	this->next = next;
}

Book* Book::getNext() const {
	return next;
}

void Book::setTitle(string title) {
	this->title = title;
}

string Book::getTitle() const {
	return title;
}

void Book::setPublisher(string publisher) {
	this->publisher = publisher;
}

string Book::getPublisher() const {
	return publisher;
}

void Book::setYear(int Year) {
	this->year = Year;
}

int Book::getYear() const {
	return year;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getAuthor() const {
	return author;
}

void Book::setIsbn_number(unsigned int isbn_number) {
	this->isbn_number = isbn_number;
}

unsigned int Book::getIsbn_number() const {
	return isbn_number;
}


