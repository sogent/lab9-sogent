#pragma once
// Sarah Ogent
// 11/13/2021
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{


    friend ostream& operator<<(ostream& output, const Fraction& fract);
    friend istream& operator>>(istream& input, Fraction& fract);





	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	//int getGCD(int num1, int num2);
    //int numerator;
    //int denominator;

public:
	void reduce();
    //default constructor
    Fraction();
    const Fraction operator+(Fraction rhs);
    const Fraction operator-(Fraction rhs);
    const Fraction operator*(Fraction rhs);
    const Fraction operator/(Fraction rhs);
    bool operator==(const Fraction rhs);
    int getGCD(int num1, int num2);
    int getLCD(int num1, int num2);

    int numerator;
    int denominator;


};

