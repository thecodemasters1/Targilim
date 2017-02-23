#pragma once
#include "Drink.h"

class Wine : public Drink
{
public:
	Wine(const char * name, int year);
	~Wine();
	virtual const char * prepare();
	virtual const char * getName();
	
private:
	int m_year;

};