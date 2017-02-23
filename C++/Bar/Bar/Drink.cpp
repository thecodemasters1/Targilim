#include "Drink.h"

Drink::Drink()
{
	m_name = NULL;
}

Drink::Drink(const char * name)
{
	m_name = new char[strlen(name)+1];
	strcpy(m_name, name);
}

Drink::~Drink()
{
	if(m_name != NULL)
	{
		delete[] m_name;
	}
}

const char * Drink::getName()
{
	return m_name;
}