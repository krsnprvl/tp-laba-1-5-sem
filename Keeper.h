#pragma once
#include "Airplane.h"
#include "Train.h"
#include "Car.h"
#include <fstream>
class Keeper
{
	Carrier** data;
	int size;
public:
	Keeper();
	~Keeper();
	int getSize();
	void add();
	void add(int _type, ifstream& fin);
	void edit();
	void del();
	void save();
	void load();
	friend ostream& operator<<(ostream& out, Keeper& obj);
};