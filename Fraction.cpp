// Your Name
// Today's date
// Lab 10

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Fraction::Fraction(){
    numerator=0;
    denominator=0;
}

ostream& operator<<(ostream& output, const Fraction& fract){
    char slash='/';
    output<<fract.numerator;
    output<<slash;
    output<<fract.denominator;
    return output;

}

istream& operator>>(istream& input, Fraction& fract){
    char slash='/';
    input>> fract.numerator;
    input>>slash;
    input>>fract.denominator;

    return input;
}


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
    Fraction fraction;
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

    if(this->numerator<0&&this->denominator>0){
        this->numerator=this->numerator*1;
        this->denominator=this->denominator*1;
    }


    (this->numerator<0&&this->denominator>0)==(this->numerator<0&&this->denominator<0);

    (this->numerator<0&&this->denominator<0)==(this->numerator<0&&this->denominator>0);


}





const Fraction Fraction::operator+(Fraction rhs){
    Fraction result;
    this->reduce();
    rhs.reduce();

    if(this->denominator!=rhs.denominator){
        int fract1numeratorA=this->numerator*rhs.denominator;
        int fract1denominatorA=this->denominator*rhs.denominator;

        int rhsnumeratorA=rhs.numerator*this->denominator;
        int rhsdenominatorA=rhs.denominator*this->denominator;


        result.numerator=fract1numeratorA+rhsnumeratorA;
        result.numerator=result.numerator*-1;
        result.denominator=fract1denominatorA;
        result.denominator=result.denominator*-1;
        result.reduce();
        return result;

    }

    if(this->denominator==rhs.denominator){
        result.numerator=this->numerator+rhs.numerator;
        result.denominator=this->denominator;
        result.reduce();
        return result;
    }

}


const Fraction Fraction::operator-(Fraction rhs){
    Fraction result;
    this->reduce();
    rhs.reduce();

    if(this->denominator!=rhs.denominator){
        int fract1numeratorA=this->numerator*rhs.denominator;
        int fract1denominatorA=this->denominator*rhs.denominator;


        int rhsnumeratorA=rhs.numerator*this->denominator;
        int rhsdenominatorA=rhs.denominator*this->denominator;



        result.numerator=fract1numeratorA-rhsnumeratorA;
        result.denominator=fract1denominatorA;
        result.reduce();
        return result;
    }

    if(this->denominator==rhs.denominator){
        result.numerator=this->numerator-rhs.numerator;
        result.denominator=this->denominator;
        if((result.numerator=this->numerator-rhs.numerator)==0){
            result.numerator=0;
            result.denominator=0;
            return result;

        }else{
            result.reduce();
            return result;
        }
    }
}

const Fraction Fraction::operator*(Fraction rhs){
    Fraction result;

    result.numerator=this->numerator*rhs.numerator;
    result.denominator=this->denominator*rhs.denominator;

    result.numerator=result.numerator;
    result.denominator=result.denominator;

    result.reduce();
    return result;
}

const Fraction Fraction::operator/(const Fraction rhs){
    Fraction result;
    result.numerator=this->numerator*rhs.denominator;
    result.denominator=this->denominator*rhs.numerator;

    result.numerator=result.numerator*-1;
    result.denominator=result.denominator*-1;

    result.reduce();
    return result;
}

bool Fraction::operator==(const Fraction rhs){

    //this->reduce();
    //rhs.reduce();

    return ((this->numerator==rhs.numerator)&&(this->denominator==rhs.denominator));
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
