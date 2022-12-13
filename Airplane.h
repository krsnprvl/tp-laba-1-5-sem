#pragma once
#include "Carrier.h"

class Airplane : public Carrier
{
	string type;
	string name;
	int volume;
	int size;
	string city;
public:
	Airplane();
	Airplane(ifstream &fin);
	~Airplane();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};