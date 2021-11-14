// Your Name
// Today's date
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

/* 
General pattern for overloaded operators: 
   1. Declare new object as local variable 
   2. Assign values as needed--in this case, to numerator & denominator
   3. return new object
Note that for most operators, the return type is a const object or const reference to object. 
That's so this: 

A + B = C; 

isn't legal, but 

C = A + B; 

is. 
*/ 
