#ifndef ASEMBLER_H
#define ASEMBLER_H



#include<iostream>
#include <fstream>
#include <map>
#include "Simbol.h"
#include "Sifra.h"
#include <vector>
#include "RelZapis.h"
#include <algorithm>

using namespace std;

class Asembler {

public:
	Asembler(); 

	void prvi(ifstream& fajl, int poc);

	void drugi(ifstream& fajl);

	string decuBin(int broj, int duzina);

	string binuHeks(string sBinary);

	string obrni(string resenje, int duzina);

	string kodZaRegistar(string reg) {
		if (reg == "r0") return "000";
		if (reg == "r1") return "001";
		if (reg == "r2") return "010";
		if (reg == "r3") return "011";
		if (reg == "r4") return "100";
		if (reg == "r5") return "101";
		if (reg == "r6") return "110";
		if (reg == "r7") return "111";
	}

	string skiniPrvi(string poslato) {
		string resenje;
		for (int i = 1; i < poslato.length(); i++) {
			resenje += poslato.at(i);
		}
		return resenje;
	}

	int rbsekcije(string labela) {
		string sekcija = tabela[labela]->sekcija;
		string resenje = ".";
		for (int i = 0; i < sekcija.length(); i++) { resenje += sekcija.at(i); }
		return tabela[resenje]->rb;
	}

	bool jelibroj(string s) {
		if (s[0] == '-') {
			for (int i = 1; i < s.length(); i++) {
				if (!isdigit(s.at(i))) { return false; }
			}
		}
		else {
			for (int i = 0; i < s.length(); i++) {
				if (!isdigit(s.at(i))) { return false; }
			}
		}
		return true;
	}

	void ispisudat(ofstream& fajl) {
		fajl<<"ime\t" << "rb \t" << "sekcija" << " vr. \t" << "l/g\t" << "flegovi " << "vel.\t" << "pocetak" << "\n";
		for (map<string, Simbol* >::const_iterator it = tabela.begin(); it != tabela.end(); ++it)
		{
			fajl << it->second->ime << "\t" << it->second->rb << "\t" << it->second->sekcija << "\t" << it->second->vrednost << "\t" << it->second->lokalnost << "\t" << it->second->flegovi << "\t" << it->second->velicina << "\t" << it->second->pocetakSekcije << "\n";

		}
		fajl << "\n#data \n" << binuHeks(id) << "\n";
		fajl << "\n#text \n" << binuHeks(it) << "\n \n";
		fajl << "\n#rodata \n" << binuHeks(ir) << "\n";
		fajl << "#rel text \n";
		fajl << "ofset\t" << "tip\t\t" << "vr" << "\n";
		for (int i = 0; i < relzapisit.size(); i++) {
			fajl << relzapisit[i]->ofset << "\t" << relzapisit[i]->tip << "\t\t" << relzapisit[i]->vr << "\n";
		}
		fajl << "\n#rel data \n";
		fajl << "ofset\t" << "tip\t\t" << "vr" << "\n";
		for (int i = 0; i < relzapisid.size(); i++) {
			fajl << relzapisid[i]->ofset << "\t" << relzapisid[i]->tip << "\t\t" << relzapisid[i]->vr << "\n";
		}
		fajl << "\n#rel rodata \n";
		fajl << "ofset\t" << "tip\t\t" << "vr" << "\n";
		for (int i = 0; i < relzapisir.size(); i++) {
			fajl << relzapisir[i]->ofset << "\t" << relzapisir[i]->tip << "\t\t" << relzapisir[i]->vr << "\n";
		}
	}

	bool jeliizraz(string izraz) {
		for (int i = 0; i < izraz.length(); i++) {
			if (izraz[i] == '+' || izraz[i] == '-') { return true; }
		}
		return false;
	}

	/*string jelivalidan(string str, int brojac) {
		string resenje = "nv"; //nije validan izraz
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		int text = 0;
		int data = 0;
		int rodata = 0;
		int bss = 0;
		int prethodni = 0;
		int bilo = 1; //0-minus 1-plus
		int t = 0;
		int d = 0;
		int r = 0;
		int b = 0;
		int i = 0;
		int zbir = 0;
		for ( i = 0; i < str.length(); i++) {
			if (str[i] == '+' || str[i] == '-') {
				if (i == 0) { if (str[i] == '+') bilo = 1; else bilo = 0; continue; }
				string operand;
				for (int j = prethodni; j < i; j++) operand += str[j];
				if (tabela[operand] == 0) { cerr << "nepoznat simbol " << operand; exit(EXIT_FAILURE); }
				if (bilo == 0) {
					if (tabela[operand]->sekcija == "text") { text--; t += stoi(tabela[operand]->vrednost); }
					if (tabela[operand]->sekcija == "data") { data--; d += stoi(tabela[operand]->vrednost);}
					if (tabela[operand]->sekcija == "rodata") { rodata--; r += stoi(tabela[operand]->vrednost);}
					if (tabela[operand]->sekcija == "bss") { bss--; b += stoi(tabela[operand]->vrednost);}
				}
				if (bilo == 1) {
					if (tabela[operand]->sekcija == "text") { text++; t -= stoi(tabela[operand]->vrednost);}
					if (tabela[operand]->sekcija == "data") { data++; d-= stoi(tabela[operand]->vrednost);}
					if (tabela[operand]->sekcija == "rodata") { rodata++; r -= stoi(tabela[operand]->vrednost);}
					if (tabela[operand]->sekcija == "bss") { bss++; b -= stoi(tabela[operand]->vrednost);}
				}
				prethodni = i + 1;
				if (str[i] == '+') bilo = 1; else bilo = 0;
			}
		}
		string operand;
		for (int j = prethodni; j < str.length(); j++) operand += str[j];
		if (tabela[operand] == 0) { cerr << "nepoznat simbol " << operand; exit(EXIT_FAILURE); }
		if (bilo == 0) {
			if (tabela[operand]->sekcija == "text") text--;
			if (tabela[operand]->sekcija == "data") data--;
			if (tabela[operand]->sekcija == "rodata") rodata--;
			if (tabela[operand]->sekcija == "bss") bss--;
		}
		if (bilo == 1) {
			if (tabela[operand]->sekcija == "text") text++;
			if (tabela[operand]->sekcija == "data") data++;
			if (tabela[operand]->sekcija == "rodata") rodata++;
			if (tabela[operand]->sekcija == "bss") bss++;
		}
		if (text != 0 && data != 0) { return resenje; }
		if (text != 0 && rodata != 0) { return resenje; }
		if (text != 0 && bss != 0) { return resenje; }
		if (rodata != 0 && data != 0) { return resenje; }
		if (bss != 0 && data != 0) { return resenje; }
		if (bss != 0 && rodata != 0) { return resenje; }
		if (text < 0 || text>1 || data < 0 || data>1 || rodata < 0 || rodata>1 || bss < 0 || bss>1) { return resenje; }
		if (text == 0 && data == 0 && rodata == 0 && bss == 0) { int zbir = t + d + b + r; return to_string(zbir); }
		if (text == 1) { zbir = t + d + b + r; RelZapis *rz = new RelZapis(to_string(brojac-2), "R_386_32", rbsekcije(".text")); } //brojac-2
		if (data == 1) {  zbir = t + d + b + r; RelZapis *rz = new RelZapis(to_string(brojac - 2), "R_386_32", rbsekcije(".data")); }
		if (rodata == 1) { zbir = t + d + b + r; RelZapis *rz = new RelZapis(to_string(brojac - 2), "R_386_32", rbsekcije(".rodata")); }
		if (bss == 1) {  zbir = t + d + b + r; RelZapis *rz = new RelZapis(to_string(brojac - 2), "R_386_32", rbsekcije(".bss")); }
		resenje = to_string(zbir);
		return resenje;
	}*/
	

private:
	 map<string, Simbol*> tabela;
	 map<string, Sifra*> sifrarnik;
	 vector<RelZapis* > relzapisi;
	 vector<RelZapis* > relzapisid;
	 vector<RelZapis* > relzapisit;
	 vector<RelZapis* > relzapisir;
	 string it;
	 string id;
	 string ir;
};

#endif