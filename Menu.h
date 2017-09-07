#include "List.h"
#include <iostream>
using namespace std;

#pragma once
class Menu
{
	public:
		Menu();
		~Menu();

		int main_menu();
		void submenu_edit();
		void check_input(unsigned int &);

	private:
		List *list = NULL;
		Book* book = NULL;
};