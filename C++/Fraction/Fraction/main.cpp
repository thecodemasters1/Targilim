#include <stdio.h>
#include "Fraction.h"

int main()
{
	Fraction f1 = Fraction(5, 8);
	Fraction f2 = Fraction(1, 2);
	Fraction f3;

	//Multiply Test
	f1.print();
	printf(" * ");
	f2.print();
	
	printf(" = ");
	f3 = f1 * f2;
	f3.print();
	printf("\n");

	f1.print();
	printf(" * 3  = ");
	f3 = f1 * 3;
	f3.print();
	printf("\n");

	//Float Test
	f3.print();
	printf(" = %f\n", (float)f3);

	//Add Test
	f1.print();
	printf(" + ");
	f2.print();
	
	printf(" = ");
	f3 = f1 + f2;
	f3.print();
	printf("\n");

	f1.print();
	printf(" + 2 = ");
	f3 = f1 + 2;
	f3.print();
	printf("\n");

	//Divide Test
	f1.print();
	printf(" / ");
	f2.print();

	printf(" = ");
	f3 = f1 / f2;
	f3.print();
	printf("\n");

	f1.print();
	printf(" / 3  = ");
	f3 = f1 / 3;
	f3.print();
	printf("\n");

	//Compare Test
	f1 = Fraction(2, 4);
	f2 = Fraction(1, 2);
	printf("f1 and f2 are %sequal.\n", f1 == f2 ? "":"not ");

	f2 = Fraction(1, 3);
	printf("f1 and f2 are %sequal.\n", f1 != f2 ? "not " : "");

	printf("f1 > f2 : %s\n", f1 > f2 ? "true" : "false");
	printf("f1 >= f2 : %s\n", f1 >= f2 ? "true" : "false");
	printf("f1 < f2 : %s\n", f1 < f2 ? "true" : "false");
	printf("f1 <= f2 : %s\n", f1 <= f2 ? "true" : "false");

	return 0;
}