#include "Fraction.h"

Fraction::Fraction(int mone, int mehane)
{
	m_mone = mone;
	m_mehane = mehane;
}

Fraction::Fraction()
{
	m_mone = 1;
	m_mehane = 1;
}


Fraction::~Fraction()
{
}

int Fraction::getMone() const
{
	return m_mone;
}

int Fraction::getMehane() const
{
	return m_mehane;
}

void Fraction::setMone(int mone)
{
	m_mone = mone;
}

void Fraction::setMehane(int mehane)
{
	m_mehane = mehane;
}

void Fraction::print()
{
	printf("%d/%d", m_mone, m_mehane);
}

Fraction::operator float() const
{
	return ((float)m_mone / m_mehane);
}

Fraction Fraction::operator* (const Fraction &other) const
{
	return Fraction(m_mone * other.getMone(), m_mehane * other.getMehane());
}

Fraction operator* (int num, const Fraction & frac)
{
	return Fraction(frac.getMone() * num, frac.getMehane());
}

Fraction operator* (const Fraction & frac, int num)
{
	return operator*(num, frac);
}

Fraction Fraction::operator+ (const Fraction &other) const
{
	return Fraction(m_mone * other.getMehane() + other.getMone() * m_mehane, m_mehane * other.getMehane());
}

Fraction operator+(int num, const Fraction & frac)
{
	return frac + Fraction(num, 1);
}

Fraction operator+(const Fraction & frac ,int num)
{
	return operator+(num, frac);
}

Fraction Fraction::operator- (const Fraction &other) const
{
	return Fraction(m_mone * other.getMehane() - other.getMone() * m_mehane, m_mehane * other.getMehane());
}

Fraction operator-(int num, const Fraction & frac)
{
	return frac - Fraction(num, 1);
}

Fraction operator-(const Fraction & frac ,int num)
{
	return frac - num;
}

Fraction Fraction::operator/ (const Fraction &other) const
{
	return Fraction(m_mone * other.getMehane(), m_mehane * other.getMone());
}

Fraction operator/ (int num, const Fraction & frac)
{
	return Fraction(frac.getMehane() * num, frac.getMone());
}

Fraction operator/ (const Fraction & frac, int num)
{
	return operator/(num, frac);
}

bool operator== (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 == (float)f2;
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
	return !(f1 == f2);
}

bool operator> (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 > (float)f2;
}

bool operator>= (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 >= (float)f2;
}

bool operator< (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 < (float)f2;
}

bool operator<= (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 <= (float)f2;
}

/*
template <operator op>
bool operator op (const Fraction &f1, const Fraction &f2)
{
	return (float)f1 op (float)f2;
}
*/