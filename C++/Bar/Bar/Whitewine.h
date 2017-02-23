#pragma once
#include "Wine.h"

class Whitewine : public Wine
{
public:
	Whitewine(const char * name, int year);
	~Whitewine();
	virtual const char * prepare();
};