#include "classPokupka.h"

Pokupka::Pokupka() : kol_tovara(0), sum_price(0), sum_weight(0){}

void Pokupka::setKolTovara(int kol)
{
	kol_tovara = kol + kol_tovara;
}

int Pokupka::getKolTovara()
{
	return kol_tovara;
}

void Pokupka::setAllPrice()
{
	sum_price = sum_price + (kol_tovara * getPrice());
}

float Pokupka::getAllPrice()
{
	return sum_price;
}

void Pokupka::setAllWeight()
{
	sum_weight = sum_weight + (kol_tovara * getWeight());
}

float Pokupka::getAllWeight()
{
	return sum_weight;
}

Pokupka::~Pokupka(){};