#ifndef SIMBOL_H
#define SIMBOL_H

#include <string>
using namespace std;

class Simbol {

	friend class Asembler;

public:

	Simbol(string i, int broj) {
		ime = i;
		rb = broj;
		lokalnost = "l";
		sekcija = "UND";
		velicina = -1;
		vrednost = "UND";
		flegovi = "/";
		pocetakSekcije = "/";
	}

	string getIme() {
		return ime;
	}

	int getRB() {
		return rb;
	}

	void setLokalnost(string ll) {
		lokalnost = ll;
	}

	string getLokalnost() {
		return lokalnost;
	}

	void setVrednost(string ll) {
		vrednost = ll;
	}

	string getVrednost() {
		return vrednost;
	}

	void setSekcija(string ll) {
		sekcija = ll;
	}

	string getSekcija() {
		return sekcija;
	}

	void setFlegovi(string ll) {
		flegovi = ll;
	}

	string getFlegovi() {
		return flegovi;
	}

	void setVelicina(int i) {
		velicina = i;
	}

	int getVelicina() { 
		return velicina; 
	}


private:
	string ime;
	int rb;
	string vrednost;
	string lokalnost;
	string sekcija;
	int velicina;
	string flegovi;
	string pocetakSekcije;


};

#endif