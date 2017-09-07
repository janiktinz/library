#include "Menu.h"
using namespace std;

Menu::Menu()
{
	list = new List();
}

Menu::~Menu()
{
	delete list;
	list = NULL;
	delete book;
	book = NULL;
}

int Menu::main_menu()
{	
	while (true)
	{
		unsigned int choice = 0;
		// menue
		system("clear");
		cout << "----------------------" << endl;
		cout << "-  Buecherverwaltung  -" << endl;
		cout << "----------------------" << endl;
		cout << "(1) Buecher auflisten" << endl;
		cout << "(2) Buch anlegen" << endl;
		cout << "(3) Buch suchen" << endl;
		cout << "(4) Buecher bearbeiten" << endl;
		cout << "(5) Buecher sortieren" << endl;
		cout << "(0) Programmende" << endl;
		check_input(choice);   // input choice
		system("clear");

		switch (choice)
		{
			case 1:
				list->print();
				cout << "- Enter druecken, um fortzufahren... -";
				cin.ignore();
				cin.ignore();
				cout << endl;
				break;
			case 2:
				cout << "Geben Sie ein neues Buch ein: " << endl;
				book = new Book();
				book->edit();   
				list->insert_head(book);   // insert a new book
				system("cls");
				break;
			case 3:
			{
				// search a book with ISBN
				unsigned int choice = 0;
				cout << "Welches Buch suchen Sie (Bitte ISBN eingeben)? " << endl;
				check_input(choice);   // input choice
				cout << endl;
				Book *resultBook = list->search(choice);   // search a book

				if (resultBook != NULL)
					resultBook->print();   // print the book
				cout << "- Enter druecken, um fortzufahren... -";
				cin.ignore();
				cin.ignore();
				cout << endl;
				break;
			}
			case 4:
				submenu_edit();   // edit submenu
				break;
			case 5:
				list->merge_sort();   // sort all books
				cout << "Die Buecher sind jetzt nach Jahren sortiert (fruehstes Jahr zuerst)! " << endl;
				cout << "- Enter druecken, um fortzufahren... -";
				cin.ignore();
				cin.ignore();
				cout << endl;
				break;
			case 0:
				cout << "Programm beendet! " << endl;
				return 0;
			default:
				cout << "Ungueltige Eingabe! " << endl;
				cout << endl;
				break;
		}
	}
}

void Menu::submenu_edit()
{
	while (true)
	{
		unsigned int choice = 0;
		system("cls");
		cout << "----------------------" << endl;
		cout << "-  Buecherverwaltung  -" << endl;
		cout << "----------------------" << endl;
		cout << "(1) Buch bearbeiten" << endl;
		cout << "(2) Buch loeschen" << endl;
		cout << "(0) Zurueck" << endl;

		check_input(choice);
		system("cls");

		if (choice == 0)
			return;

		// search a book with ISBN
		unsigned int isbn = 0;
		cout << "Bitte geben Sie die ISBN des Buches ein: " << endl;
		check_input(isbn);
		cout << endl;
		Book* resultBook = list->search(isbn);   // search an isbn number
		if (resultBook != NULL)
			resultBook->print();   // print the book

		if (choice == 1 && resultBook != NULL)
			resultBook->edit();   // edit the book
		
		if(choice == 2 && resultBook != NULL)
			list->delete_book(resultBook);   // delete the book
	
		if (choice >= 3)
		{
			cout << "Ungueltige Eingabe! " << endl;
			cout << endl;
		}
	}
}

void Menu::check_input(unsigned int &choice)   // check the input of correctness 
{
	cout << "Eingabe > ";
	cin >> choice;
	while (!cin)
	{
		try
		{
			throw "- Falsche Eingabe! Geben Sie eine Zahl ein! -";
		}

		catch (const char* str)
		{
			cout << str << endl;
		}
		cin.clear();
		cin.ignore();

		cout << "Eingabe > ";
		cin >> choice;
	}
}


