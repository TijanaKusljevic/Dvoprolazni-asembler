#ifndef SIFRA_H
#define SIFRA_H


#include <string>

using namespace std;


class Sifra {

	friend class Asembler;

public:
	Sifra() {};
	Sifra(string z, string k) { kod = k; zapis = z; };
	~Sifra() {};
	std::string getKod();
	std::string getZapis();
	void setKod(std::string kod1);
	void setZapis(std::string kod1);

private:
	std::string zapis;
	std::string kod;


};

#endif