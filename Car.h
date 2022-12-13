#pragma once
#include "Carrier.h"

class Car : public Carrier
{
	int year;
	string brand;
	string model;
	string city;
	int time;
	int volume;
public:
	Car();
	Car(ifstream &fin);
	~Car();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};
