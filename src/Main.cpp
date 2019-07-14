#include<iostream>
#include <string>
#include <fstream>
#include <regex>
#include "Asembler.h"
using namespace std;

int main(int broj, char* niz[]) {

	string ulazni = niz[1];
	string izlazni = niz[2];
	int poc = atoi(niz[3]);


	ifstream fajl;
	fajl.open(ulazni);

	Asembler* a = new Asembler();

	a->prvi(fajl, poc);
	fajl.close();
	fajl.open(ulazni);
	a->drugi(fajl);
	fajl.close();

	ofstream myfile;
	myfile.open(izlazni);
	a->ispisudat(myfile);
	myfile.close();
	//cout << "\n\n\n\n\n";
//	cout<<a->jelivalidan("a - b +m", 12);
	//if (regex_match("$", regex("\\$.+"))) { cout << "OK"; }

	/*string r;
	int n = 11;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	cout <<"\n"<< r<<"\n";*/
	
	//cout<<a->binuHeks("01011101");
	

}

