
#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This file will be included when grading
// For testing, feel free to modify this file to ensure your class is 
// working.


int main() {
	// Input/output files
	ifstream fin("/Users/sogent/CLionProjects/lab9-sogent/input.txt");
	ofstream fout("output.txt");

	// Throw error if can't open input file
	if (!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}


    Fraction f1;
    Fraction f2;
    cout<<"Fraction 1:"<<endl;
    cin>>f1;
    f1.reduce();
    cout<<f1<<endl;
    cout<<"Fraction 2:"<<endl;
    cin>>f2;
    f2.reduce();
    cout<<f2<<endl;

    cout<<f1 <<" + "<< f2<<endl;
    cout<<f1+f2<<endl;
    cout<<f1 <<" - "<< f2<<endl;
    cout<<f1-f2<<endl;
    cout<<f1 <<" * "<< f2<<endl;
    cout<<f1*f2<<endl;
    cout<<f1 <<" / "<< f2<<endl;
    cout<<f1/f2<<endl;

    if(f1==f2){
        cout<<"the fractions are equivalent"<<endl;
    }else{
        cout<<"the fractions are not equivalent"<<endl;
    }







	// While there's data in the file, read in a line and calculate it
	while (fin.good())
	{

		// Read in two fractions and the operator to perform
		Fraction fract1, fract2;
		char oper;
		fin >> fract1 >> oper >> fract2;

		// Print out original functions read in
		fout << fract1 << " " << oper << " " << fract2 << " = ";

		// Do math on them
		switch (oper)
		{
		case '+':
			fout << fract1 + fract2 << endl;
            //cout<<fract1+fract2<<endl;
			break;

		case '-':
			fout << fract1 - fract2 << endl;
            //cout<<fract1-fract2<<endl;
			break;

		case '*':
			fout << fract1 * fract2 << endl;
                //cout<<fract1*fract2<<endl;
			break;

		case '/':
			fout << fract1 / fract2 << endl;
			break;

		case '=':

			if (fract1 == fract2)
				fout << "True" << endl;
			else
				fout << "False" << endl;

			break;


		}


	}




/*
	// Close files
	fin.close();
	fout.close();


*/
	// Quit without error
	return 0;

}