#include"classPokupka.h"
class Check : public Pokupka
{
public:
	void printProductInfo()
	{
		cout << "The name of the product: " << name << endl;
		cout << "The prise of the product: " << cost << endl;
		cout << "Product weight: " << weight << endl;
		cout << "Number of this product in the store: " << theNumber << endl;
		cout << "______________________________________" << endl;
	}

	void printPokupkaInfo()
	{
		cout << "Quantity of purchased goods: [" << getName() << "] = " << getKolTovara() << endl;
		cout << "Total cost : " << getAllPrice() << endl;
		cout << "Total weight: " << getAllWeight() << endl;
		cout << "______________________________________" << endl;
	}
};