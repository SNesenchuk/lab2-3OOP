#include<iostream>
#include"classCheck.h"

using namespace std;
int state;
const string succ_delete = "Information was succesfully deleted";

template <class T>
class ShablonList
{
	struct Element
	{
		T data;
		Element *next;
		Element *priv;
	};

	ofstream Fout;
	Element *head;
	Element *tail;
	int elementsCount;

public:

	ShablonList()
	{
		head = NULL;
		tail = NULL;
		elementsCount = 0;
	}

	void AddToFile(T data)
	{

		try
	{

			Fout.open("Data Base.DAT", ios::binary | ios::app);
			state = Fout.rdstate();
			if (state)
			{
				if (state & ios::failbit)
				{
					cout << "it's failbit" << endl;
					throw EXP_FILE_OPEN("File can't be opened ", 20);
					cin.clear(0);
				}

				if (state & ios::badbit)
				{
					cout << "it's badbit" << endl;
					throw EXP_FILE_OPEN("File can't be opened ", 20);
					cin.clear(0);
				}
			}
				Fout.write(reinterpret_cast<char*>(&data), sizeof(data));
				Fout.close();
		}
		
		catch (EXP_FILE_OPEN obj)
		{
			exceptionProcessing(obj.whatMessage(), obj.whatKod());
			fflush(stdin);
		}

	}

	
	void reWriteFile()
	{
		Element *temp;
		Fout.open("Data Base.DAT", ios::binary | ios::app | ios_base::trunc);
		temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			Fout.write(reinterpret_cast<char*>(&(temp->data)), sizeof((temp->data)));
			temp = temp->next;
		}
		Fout.close();
	}

	void ReadFromFile()
	{
		try
		{
			long fileSize = 0;
			ifstream Fin;
			Fin.open("Data Base.DAT", ios::binary | ios_base::in);
			state = Fin.rdstate();
			if (state)
			{
				if (state & ios::failbit)
				{
					cout << "it's failbit" << endl;
					throw EXP_FILE_OPEN("File can't be opened, because it's not created", 20);
					cin.clear(0);
				}
				if (state & ios::badbit)
				{
					cout << "it's badbit" << endl;
					throw EXP_FILE_OPEN("File can't be opened, because it's not created", 20);
					cin.clear(0);
				}
			}
			Fin.seekg(0, ios::end);
			fileSize = Fin.tellg();
			Fin.seekg(0);
			if (fileSize == 0)
				throw EXP_FILE_EMPTY("File is empty , data can't be read ", 50);


			while (true)
			{
				if (head == NULL)
				{
					if (Fin.eof()) break;
					Element *oneMore = new Element;
					head = oneMore;
					head->next = NULL;
					tail = oneMore;
					Fin.read(reinterpret_cast<char*>(&(oneMore->data)), sizeof(oneMore->data));
					elementsCount++;
				}
				else
				{
					if (Fin.eof()) break;
					Element *oneMore = new Element;
					oneMore->next = head;
					head->priv = oneMore;
					head = oneMore;
					Fin.read(reinterpret_cast<char*>(&(oneMore->data)), sizeof(oneMore->data));
					elementsCount++;
				}
			}
			system("cls");
			cout << "Information succesfully added from file to program" << endl;

		}
		catch (EXP_FILE_OPEN obj)
		{
			exceptionProcessing(obj.whatMessage(), obj.whatKod());
			fflush(stdin);
		}
		catch (EXP_FILE_EMPTY obj)
		{
			exceptionProcessing(obj.whatMessage(), obj.whatKod());
			fflush(stdin);
		}
	}

	void addElementHead(T data)
	{
		if (head == NULL)
		{
			Element *oneMore = new Element;
			oneMore->data = data;
			head = oneMore;
			AddToFile(data);
			head->next = NULL;
			tail = oneMore;
			elementsCount++;
		}
		else
		{
			Element *oneMore = new Element;
			oneMore->data = data;
			oneMore->next = head;
			head->priv = oneMore;
			head = oneMore;
			AddToFile(data);
			elementsCount++;
		}
		system("cls");
		cout << "Information succesfully added to list" << endl;
		system("pause");
	}

	void deleteElement(string name)
	{
		if (elementsCount == 0)
		{
			cout << "There is no information in this list, please add some" << endl;
			return;
		}

		int count = 0;
		Element *temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			count++;
			if (temp->data.getName() == name)
				break;
			temp = temp->next;
		}

		if (count == 1 && (head->next))
		{
			Element *temp = head;
			head = head->next;
			head->priv = NULL;
			delete temp;
			elementsCount--;
			system("cls");
			cout << succ_delete << endl;
			system("pause");
			return;
		}
		else if (count == 1 && (head == tail))
		{
			head->next = NULL;
			head = NULL;
			delete head;
			elementsCount = 0;
			system("cls");
			cout << succ_delete << endl;
			system("pause");
			return;
		}

		if (elementsCount == count)
		{
			Element *temp = tail;
			tail = tail->priv;
			tail->next = NULL;
			delete temp;
			elementsCount--;
			system("cls");
			cout << succ_delete << endl;
			system("pause");
			return;
		}

		temp = head;
		Element *temp2;											  //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные
		for (int i = 0; i < (count - 1); i++) temp = temp->next;

		temp2 = temp;
		temp2->priv->next = temp->next;
		temp2->next->priv = temp->priv;
		delete temp;
		elementsCount--;
		system("cls");
		cout << succ_delete << endl;
		system("pause");
	}

	void makeBuy(string name)
	{
		int flag = 0;
		int kol;
		Element *temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			if (temp->data.getName() == name)
			{
				flag = 1;
				break;
			}
			temp = temp->next;
		}

		if (flag == 0)
		{
			cout << "This product wasn't found, please ask for another" << endl;
			return;
		}

		cout << "Enter the number of goods , which you want to buy" << endl << "The values of the amount payable and the total weight of the purchase will be calculated automatically" << endl;
		kol = CheckForVVOD::checkForNumber(temp->data.getTheNumber());
		temp->data.changeTheNumber(kol);
		temp->data.setKolTovara(kol);
		temp->data.setAllPrice();
		temp->data.setAllWeight();

	}

	int printAllProducts()
	{
		if (elementsCount == 0)
		{
			cout << "The list does not contain any information! Add some, please" << endl;
			return 0;
		}

		Element *temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			temp->data.printProductInfo();
			temp = temp->next;
		}
		return elementsCount;
	}

	void printAllBuys()
	{
		if (elementsCount == 0)
		{
			cout << "The list does not contain any information! Add some, please" << endl;
			return;
		}

		Element *temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			temp->data.printPokupkaInfo();
			temp = temp->next;
		}
	}

	~ShablonList()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}
};
