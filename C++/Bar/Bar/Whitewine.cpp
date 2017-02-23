#include "Whitewine.h"

Whitewine::Whitewine(const char * name, int year) : Wine(name, year)
{
}

Whitewine::~Whitewine()
{
}

const char * Whitewine::prepare()
{
	return "Well, all you need to do is cool the wine and serve it.";
}
