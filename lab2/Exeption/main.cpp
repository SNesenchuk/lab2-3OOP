#include<iostream>
#include<locale>
#include"ShablonList.h"
#include<Windows.h>
#include<conio.h>
#include<fstream>

bool isAdmin = false;
bool isPokupatel = false;

string checkForInput()
{
	string str;
	str = CheckForVVOD::checkName();
	return str;
}

void mainMenu()
{
	bool isExit = true;
	int choice = 0;
	cout << "You are welcome, who are you?" << endl;
	cout << "1 - Shop worker" << endl;
	cout << "2 - Client	" << endl;
	cout << "3 - Exit" << endl;
	choice = CheckForVVOD::getrange(1, 3);
	switch (choice)
	{
	case 1:
		isAdmin = true;
		isPokupatel = false;
		break;
	case 2:
		isAdmin = false;
		isPokupatel = true;
		break;
	case 3:
		isAdmin = false;
		isPokupatel = false;
		break;
	}
}

int menu()
{
	int choice;
	cout << "1 - Add a new product" << endl;
	cout << "2 - Display a list of goods" << endl;
	cout << "3 - Remove the product and all related purchases" << endl;
	cout << "4 - Upload data from file" << endl;
	cout << "5 - Save changes in file" << endl;
	cout << "6 - Exit to the main menu" << endl;
	cout << "Your choise: " << endl;
	cout << ">> " << endl;
	choice = CheckForVVOD::getrange(1, 6);
	return choice;
}

int menu1()
{
	int choice;
	cout << "1 - Make a purchase" << endl;
	cout << "2 - Display information about purchases" << endl;
	cout << "3 - Exit from program" << endl;
	choice = CheckForVVOD::getrange(1, 3);
	return choice;
}

void addNewProduct(ShablonList<Check> &list)
{
	string name;
	float price;
	float weight;
	int theNumber;
	Check a;
	//ofstream obj;
	//obj.open("DATA BASE.txt", ios_base::app);
	cout << "Enter the name of the product: " << endl;
	name = checkForInput();
	a.setName(name);
	//obj << name << "\n";

	cout << "Enter the price of the product: " << endl;
	price = CheckForVVOD::checkForFloat();
	a.setPrice(price);
	//obj << price << "\n";

	cout << "Enter the weight of the product: " << endl;
	weight = CheckForVVOD::checkForFloat();
	a.setWeight(weight);
	//obj << weight << "\n";

	cout << "Enter the number of product to add it to the store " << endl;
	theNumber = CheckForVVOD::checkForFloat();
	a.setTheNumber(theNumber);
	//obj << theNumber << "\n";

	//	obj.close();
	list.addElementHead(a);
	system("cls");
}

int main()
{
	int n = 0;
	bool isExit = true;
	bool youWorking = false;
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ShablonList <Check> list;
	string name;
	int kol = 0;
	while (isExit)
	{
		mainMenu();
		if (isAdmin)
		{
			youWorking = true;
			system("cls");
			while (youWorking)
			{
				switch (menu())
				{
				case 1:
					system("cls");
					addNewProduct(list);
					break;
				case 2:
					system("cls");
					list.printAllProducts();
					break;
				case 3:
					system("cls");
					cout << "List of products available for removing: " << endl;
					list.printAllProducts();
					cout << "Enter the name of the product you want to delete: " << endl;
					name = checkForInput();
					list.deleteElement(name);
					break;
				case 4:
					list.ReadFromFile();
					break;
				case 5:
					list.reWriteFile();
					break;
				case 6:
					youWorking = false;
					system("cls");
					isAdmin = false;
					isPokupatel = false;
					break;
				}
			}
		}
		else if (isPokupatel)
		{
			youWorking = true;
			system("cls");
			while (youWorking)
			{
				switch (menu1())
				{
				case 1:
					system("cls");
					cout << "List of products available for purchasing: " << endl;
					n = list.printAllProducts();
					if (n > 0)
					{
						cout << "Enter the name of the product you want to buy: " << endl;
						name = checkForInput();
						list.makeBuy(name);
					}
					break;
				case 2:
					system("cls");
					list.printAllBuys();
					break;
				case 3:
					youWorking = false;
					isAdmin = false;
					isPokupatel = false;
					system("cls");
					break;
				}
			}
		}
		else
			isExit = false;
	}
	cout << "See you soon!" << endl;
	return 0;
}