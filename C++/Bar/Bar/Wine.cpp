#include "Wine.h"

Wine::Wine(const char * name, int year) : Drink(name), m_year(year)
{
}

Wine::~Wine()
{
}

const char * Wine::getName()
{
	char * buff = new char[256];
	sprintf(buff, "%s (year %d)", m_name, m_year);
	return buff;
}

const char * Wine::prepare()
{
	return "Well, all you need to do is pour it into a glass and serve.";
}