#pragma once
#include "Wine.h"

class Redwine : public Wine
{
public:
	Redwine(const char * name, int year);
	~Redwine();
	virtual const char * prepare();
};