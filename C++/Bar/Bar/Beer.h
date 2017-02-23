#pragma once
#include "Drink.h"

class Beer : public Drink
{
public:
	Beer(const char * name);
	~Beer();
	virtual const char * prepare();
	
};