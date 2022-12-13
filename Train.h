#pragma once
#include "Carrier.h"

class Train : public Carrier
{
	string name;
	int year;
	string route;
	int vagon;
	int volume;
public:
	Train();
	Train(ifstream& fin);
	~Train();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};