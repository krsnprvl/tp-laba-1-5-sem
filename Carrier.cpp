#include "Carrier.h"

void Carrier::setType(int _type)
{
	type = _type;
}

int Carrier::getType()
{
	return type;
}

bool Carrier::isError()
{
	return this->error;
}

void Carrier::setError(bool _error)
{
	this->error = _error;
}

Carrier::~Carrier()
{
}