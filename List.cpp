#include "List.h"
#include <fstream>
using namespace std;

List::List()
{
	Book *newBook = new Book;
	ifstream csvread;
	csvread.open("data.csv", ios::in);

	if (csvread)
	{
		string s = "";
		unsigned int counter_field = 0;

		// read data
		while (getline(csvread, s, ';'))
		{
			if (counter_field == 0)
				newBook->setAuthor(s);

			if (counter_field == 1)
				newBook->setTitle(s);

			if (counter_field == 2)
				newBook->setYear(atoi(s.c_str()));

			if (counter_field == 3)
				newBook->setPublisher(s);

			if (counter_field == 4)
				newBook->setIsbn_number(atoi(s.c_str()));
			counter_field++;

			if (counter_field > 4)
			{
				counter_field = 0;
				insert_tail(newBook);
				newBook = new Book;
			}
		}
		cout << "Daten erfolgreich importiert! " << endl;
		cout << endl;
		csvread.close();
	}
	else
	{
		cout << "Fehler beim Lesen der Datei! " << endl;
		cout << endl;
	}
}

List::~List()
{
	if (head != NULL)
	{
		Book *current = head;
		ofstream csvwrite;
		csvwrite.open("data.csv", ios::out);

		if (csvwrite)
		{
			// write books in file
			while (current != NULL)
			{
				csvwrite << current->getAuthor() << ";";
				csvwrite << current->getTitle() << ";";
				csvwrite << current->getYear() << ";";
				csvwrite << current->getPublisher() << ";";
				csvwrite << current->getIsbn_number() << ";";
				current = current->getNext();
			}

			if (current == NULL)
			{
				cout << "Daten wurden erfolgreich exportiert! " << endl;
				cout << endl;
			}
			csvwrite.close();
		}
		else
		{
			cout << "Fehler beim Schreiben in die Datei! " << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "Exportieren nicht moeglich, da keine Buecher hinterlegt sind! " << endl;
		cout << endl;
	}
}

void List::print()
{
	Book *current = head;
	cout << "Buecher: " << endl;
	// output of all books
	while (current != NULL)
	{
		current->print();
		current = current->getNext();
	}
}

void List::insert_head(Book* newBook)
{
	// insert a new book in the doubly linked list
	if (head == NULL)
	{
		head = newBook;
		tail = newBook;
	}
	else
	{
		newBook->setNext(head);
		head->setPrev(newBook);
		head = newBook;
	}
}

void List::insert_tail(Book* newBook)
{
	// insert a new book in the doubly linked list
	if (head == NULL)
	{
		head = newBook;
		tail = newBook;
	}
	else
	{
		tail->setNext(newBook);
		newBook->setPrev(tail);
		tail = newBook;
	}
}

void List::delete_book(Book *current)
{
	Book *removeBook = current;

	if (current->getNext() != NULL && current->getPrev() != NULL)   // delete a book in the middle
	{
		Book *tmpBooks1 = current->getPrev();
		Book *tmpBooks2 = current->getNext();
		tmpBooks1->setNext(tmpBooks2);
		tmpBooks2->setPrev(tmpBooks1);
	}
	if (current->getNext() != NULL && current->getPrev() == NULL)   // delete first book
	{
		head = head->getNext();
		head->setPrev(NULL);
	}
	if (current->getNext() == NULL && current->getPrev() != NULL)   // delete last book
	{
		tail = tail->getPrev();
		tail->setNext(NULL);
	}
	if (current->getNext() == NULL && current->getPrev() == NULL)   // delete last book of the doubly linked list
	{
		head = NULL;
		tail = NULL;
	}
	cout << "Buch " << removeBook->getTitle() << " ist geloescht! " << endl;
	cout << "- Enter druecken, um fortzufahren... -";
	cin.ignore();
	cin.ignore();
	cout << endl;

}

Book* List::search(unsigned int choice)
{
	Book *currentBooks = head;
	while (currentBooks != NULL)
	{
		if (choice == currentBooks->getIsbn_number())
			break;
		currentBooks = currentBooks->getNext();
	}
	if (currentBooks == NULL)
	{
		cout << "Das gesuchte Buch befindet sich nicht in der Datenbank! " << endl;
		cout << "- Enter druecken, um fortzufahren... -";
		cin.ignore();
		cin.ignore();
		cout << endl;
	}

	if(currentBooks != NULL && currentBooks->getPrev() != NULL)
		swap(currentBooks->getPrev(), currentBooks);
	return currentBooks;
}

void List::swap(Book* book1, Book* book2)
{
	if (book1 != book2)
	{
		Book* tmp1_prev = book1->getPrev();
		Book* tmp1_next = book2->getNext();

		// special case, if book1 direct before book2
		if (book1->getNext() == book2)
		{
			// special case, if book2 = tail or book1 = head
			if (book1->getPrev() != NULL)
				tmp1_prev->setNext(book2);
			else
				head = book2;
			if (book2->getNext() != NULL)
				tmp1_next->setPrev(book1);
			else
				tail = book1;
			book1->setPrev(book2);
			book2->setNext(book1);
			book1->setNext(tmp1_next);
			book2->setPrev(tmp1_prev);
		}
	}
}

// public function of merge_sort()
void List::merge_sort()
{
	print();
	head = merge_sort(head);
	cout << "-----------Sortierte Liste-----------" << endl;
	cout << endl;
	print();
}

// private function of merge_sort()
Book* List::merge_sort(Book *head)
{
	if (head == NULL || head->getNext() == NULL)   // head is empty or head has not a successor
		return head;
	Book *second = divide(head);

	// recursive for left half
	head = merge_sort(head);
	// recursive for right half
	second = merge_sort(second);

	// merge the two sorted halves
	return merge(head, second);
}

Book* List::merge(Book *firstNode, Book *secondNode)
{
	Book *result = NULL;
	// first linked list is empty
	if (firstNode == NULL)
		return secondNode;

	// second linked list is empty
	if (secondNode == NULL)
		return firstNode;

	if (firstNode->getYear() <= secondNode->getYear())   // first value <= second value
	{
		result = firstNode;
		result->setNext(merge(firstNode->getNext(), secondNode));
		result->getNext()->setPrev(result);
		result->setPrev(NULL);
	}
	else   // first value > second value
	{
		result = secondNode;
		result->setNext(merge(firstNode, secondNode->getNext()));
		result->getNext()->setPrev(result);
		result->setPrev(NULL);
	}
	return result;
}

// divide a doubly linked list in two halves
Book* List::divide(Book *head)
{
	Book *secondNode = head;
	Book *firstNode = head->getNext();

	while (firstNode && firstNode->getNext())
	{
		secondNode = secondNode->getNext();
		firstNode = firstNode->getNext()->getNext();
	}
	Book *tmp = secondNode->getNext();
	secondNode->setNext(NULL);
	return tmp;
}
