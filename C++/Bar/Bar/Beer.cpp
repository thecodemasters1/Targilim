#include "Beer.h"

Beer::Beer(const char * name) : Drink(name)
{
}

Beer::~Beer()
{
}

const char * Beer::prepare()
{
	return "Well, all you need to do is pour it into a glass and serve.";
}