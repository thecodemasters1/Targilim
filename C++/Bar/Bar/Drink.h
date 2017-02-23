#pragma once
#include <stdio.h>
#include <string.h>

class Drink
{
public:
	Drink();
	Drink::Drink(const char * name);
	~Drink();
	virtual const char * getName();
	virtual const char * prepare() = 0;
protected:
	char * m_name;
};

