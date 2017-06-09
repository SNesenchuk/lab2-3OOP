#include<iostream>
#include<string>
#pragma warning (disable : 4996)
using namespace std;

class Product
{
protected:
	string name;
	float cost;
	float weight;
	int theNumber;
public:
	Product(){}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setPrice(float cost)
	{
		this->cost = cost;
	}

	float getPrice()
	{
		return cost;
	}

	void setWeight(float weight)
	{
		this->weight = weight;
	}

	float getWeight()
	{
		return weight;
	}

	void setTheNumber(int theNumber)
	{
		this->theNumber = theNumber;
	}

	void changeTheNumber(int theNumber)
	{
		this->theNumber = this->theNumber - theNumber;
	}

	int getTheNumber()
	{
		return theNumber;
	}

	~Product()
	{
	}

};