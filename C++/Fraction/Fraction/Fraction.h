#pragma once
#include <stdio.h>

class Fraction
{
public:
	Fraction(int mone, int mehane);
	Fraction();
	~Fraction();
	int getMone() const;
	int getMehane() const;
	void setMone(int mone);
	void setMehane(int mehane);
	void print();
	operator float() const;
	Fraction operator* (const Fraction &other) const;
	Fraction operator+ (const Fraction &other) const;
	Fraction operator- (const Fraction &other) const;
	Fraction operator/ (const Fraction &other) const;

private:
	int m_mone;
	int m_mehane;
};

Fraction operator* (int num, const Fraction & frac);
Fraction operator* (const Fraction & frac, int num);
Fraction operator+ (int num, const Fraction & frac);
Fraction operator+ (const Fraction & frac, int num);
Fraction operator- (int num, const Fraction & frac);
Fraction operator- (const Fraction & frac, int num);
Fraction operator/ (int num, const Fraction & frac);
Fraction operator/ (const Fraction & frac, int num);

bool operator== (const Fraction &f1, const Fraction &f2);
bool operator!= (const Fraction &f1, const Fraction &f2);
bool operator> (const Fraction &f1, const Fraction &f2);
bool operator>= (const Fraction &f1, const Fraction &f2);
bool operator< (const Fraction &f1, const Fraction &f2);
bool operator<= (const Fraction &f1, const Fraction &f2);
