#include<iostream>
#include"EXP_VVOD.h"
#include"Check.h"
using namespace std;
int flags;
char c;
void exceptionProcessing(char *message, int code)
{
	
	cout << message << "Ñode: " << code << endl;
	fflush(stdin);
}

class CheckForVVOD
{
public:
	static int getrange(int x, int y)
	{
		while (1)
		{
			try
			{
				int amount;
				cin >> amount;
				flags = cin.rdstate();
				
				if (flags & ios::failbit)
				{
					cin.clear(0);
					fflush(stdin);
					throw EXP_VVOD("Invalid Input,", 140);
				}
				else if (amount < x || amount > y)
				{

					throw EXP_VVOD("There is no such menu item,", 180);
				}

				return amount;
			}
			catch (EXP_VVOD obj)
			{
				exceptionProcessing(obj.whatMessage(), obj.whatKod());
			}
		}

	}
	

	static float checkForFloat()
	{
		while (1)
		{
			try
			{
				float chislo;
				cin >> chislo;
				cin.clear();
				if (!cin.good() || cin.peek() != '\n')
					throw EXP_VVOD("Invalid input, only numbers can be entered here.", 140);
				return chislo;
			}
			catch (EXP_VVOD obj)
			{
				
				exceptionProcessing(obj.whatMessage(), obj.whatKod());
			
			}
		}
	}

	static int checkForNumber(int number)
	{
		while (1)
		{
			try
			{
				int chislo;
				
					cin >> chislo;
					flags = cin.rdstate();
					if (flags & ios::failbit)
					{
						cin.clear(0);
						fflush(stdin);
						throw EXP_VVOD("Invalid input, only numbers can be entered here.", 140);
					
					}
				if (chislo > number)
				{

					throw EXP_VVOD("Incorrect input, there is not so much product of this name in the store", 155);
				}
				if (chislo <= 0)
				{

					throw EXP_VVOD("Invalid input, you entered a negative number or 0", 327);
				}
				return chislo;
			}
			catch (EXP_VVOD obj)
			{

				exceptionProcessing(obj.whatMessage(), obj.whatKod());
			}
		}
	}

	static string checkName()
	{
		while (1)
		{
			try
			{
				string name;
				cin.clear(); fflush(stdin);
				char c;
				cin.get(c);
				if (!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122))
					throw EXP_VVOD("You can input only English symbols ", 255);
				if (!isupper(c))
					throw EXP_VVOD("The first letter must be uppercase, ", 199);
				name += c;
				for (cin.get(c); cin.rdbuf()->in_avail(); cin.get(c))
				{
					if ((c < 65 || c  > 90) && (c < 97 && c  > 122))
						throw EXP_VVOD("You can input only English symbols", 255);
					if (isupper(c))
						c = tolower(c);
					name += c;
				}
				return name;
			}
			catch (EXP_VVOD obj)
			{
				exceptionProcessing(obj.whatMessage(), obj.whatKod());
			}
		}
	}
};

