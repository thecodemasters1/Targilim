#include "Redwine.h"

Redwine::Redwine(const char * name, int year) : Wine(name, year)
{
}

Redwine::~Redwine()
{
}

const char * Redwine::prepare()
{
	return "Well, all you need to do is serve the wine at the room tempature.";
}