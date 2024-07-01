#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "Task1.h"
#include "Task2.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Завдання №1
	cout << "Завдання №1\n";	

	deleteBadWords();

	cout << endl << endl << endl;




	//Завдання №2
	cout << "Завдання №2\n";

	transliterate();

	cout << endl << endl << endl;

	return 0;
}