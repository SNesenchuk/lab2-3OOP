#include "classProduct.h"
class Pokupka : public Product
{
private:
	int kol_tovara;
	float sum_price;
	float sum_weight;

public:
	Pokupka();
	void setKolTovara(int);
	int getKolTovara();
	void setAllPrice();
	float getAllPrice();
	void setAllWeight();
	float getAllWeight();
	~Pokupka();
};