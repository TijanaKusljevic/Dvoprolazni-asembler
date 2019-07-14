#include "Asembler.h"
#include <string>
#include <sstream>
#include <regex>
#include <bitset>
using namespace std;

Asembler::Asembler() {
	
		Sifra* s = new Sifra("eqadd", "000000");
		sifrarnik["eqadd"] = s;

		s = new Sifra("neadd", "010000");
		sifrarnik["neadd"] = s;

		s = new Sifra("gtadd", "100000");
		sifrarnik["gtadd"] = s;

		s = new Sifra("aladd", "110000");
		sifrarnik["aladd"] = s;

		s = new Sifra("eqsub", "000001");
		sifrarnik["eqsub"] = s;

		s = new Sifra("nesub", "010001");
		sifrarnik["nesub"] = s;

		s = new Sifra("gtsub", "100001");
		sifrarnik["gtsub"] = s;

		s = new Sifra("alsub", "110001");
		sifrarnik["alsub"] = s;

		s = new Sifra("eqmul", "000010");
		sifrarnik["eqmul"] = s;

		s = new Sifra("nemul", "010010");
		sifrarnik["nemul"] = s;

		s = new Sifra("gtmul", "100010");
		sifrarnik["gtmul"] = s;

		s = new Sifra("almul", "110010");
		sifrarnik["almul"] = s;

		s = new Sifra("eqdiv", "000011");
		sifrarnik["eqdiv"] = s;

		s = new Sifra("nediv", "010011");
		sifrarnik["nediv"] = s;

		s = new Sifra("gtdiv", "100011");
		sifrarnik["gtdiv"] = s;

		s = new Sifra("aldiv", "110011");
		sifrarnik["aldiv"] = s;

		s = new Sifra("eqcmp", "000100");
		sifrarnik["eqcmp"] = s;

		s = new Sifra("necmp", "010100");
		sifrarnik["necmp"] = s;

		s = new Sifra("gtcmp", "100100");
		sifrarnik["gtcmp"] = s;

		s = new Sifra("alcmp", "110100");
		sifrarnik["alcmp"] = s;

		s = new Sifra("eqand", "000101");
		sifrarnik["eqand"] = s;

		s = new Sifra("neand", "010101");
		sifrarnik["neand"] = s;

		s = new Sifra("gtand", "100101");
		sifrarnik["gtand"] = s;

		s = new Sifra("aland", "110101");
		sifrarnik["aland"] = s;

		s = new Sifra("eqor", "000110");
		sifrarnik["eqor"] = s;

		s = new Sifra("neor", "010110");
		sifrarnik["neor"] = s;

		s = new Sifra("gtor", "100110");
		sifrarnik["gtor"] = s;

		s = new Sifra("alor", "110110");
		sifrarnik["alor"] = s;

		s = new Sifra("eqnot", "000111");
		sifrarnik["eqnot"] = s;

		s = new Sifra("nenot", "010111");
		sifrarnik["nenot"] = s;

		s = new Sifra("gtnot", "100111");
		sifrarnik["gtnot"] = s;

		s = new Sifra("alnot", "110111");
		sifrarnik["alnot"] = s;

		s = new Sifra("eqtest", "001000");
		sifrarnik["eqtest"] = s;

		s = new Sifra("netest", "011000");
		sifrarnik["netest"] = s;

		s = new Sifra("gttest", "101000");
		sifrarnik["gttest"] = s;

		s = new Sifra("altest", "111000");
		sifrarnik["altest"] = s;

		s = new Sifra("eqpush", "001001");
		sifrarnik["eqpush"] = s;

		s = new Sifra("nepush", "011001");
		sifrarnik["nepush"] = s;

		s = new Sifra("gtpush", "101001");
		sifrarnik["gtpush"] = s;

		s = new Sifra("alpush", "111001");
		sifrarnik["alpush"] = s;

		s = new Sifra("eqpop", "001010");
		sifrarnik["eqpop"] = s;

		s = new Sifra("nepop", "011010");
		sifrarnik["nepop"] = s;

		s = new Sifra("gtpop", "101010");
		sifrarnik["gtpop"] = s;

		s = new Sifra("alpop", "111010");
		sifrarnik["alpop"] = s;

		s = new Sifra("eqcall", "001011");
		sifrarnik["eqcall"] = s;

		s = new Sifra("necall", "011011");
		sifrarnik["necall"] = s;

		s = new Sifra("gtcall", "101011");
		sifrarnik["gtcall"] = s;

		s = new Sifra("alcall", "111011");
		sifrarnik["alcall"] = s;

		s = new Sifra("eqiret", "001100");
		sifrarnik["eqiret"] = s;

		s = new Sifra("neiret", "011100");
		sifrarnik["neiret"] = s;

		s = new Sifra("gtiret", "101100");
		sifrarnik["gtiret"] = s;

		s = new Sifra("altest", "111100");
		sifrarnik["aliret"] = s;

		s = new Sifra("eqmov", "001101");
		sifrarnik["eqmov"] = s;

		s = new Sifra("nemov", "011101");
		sifrarnik["nemov"] = s;

		s = new Sifra("gtmov", "101101");
		sifrarnik["gtmov"] = s;

		s = new Sifra("almov", "111101");
		sifrarnik["almov"] = s;

		s = new Sifra("eqshl", "001110");
		sifrarnik["eqshl"] = s;

		s = new Sifra("neshl", "011110");
		sifrarnik["neshl"] = s;

		s = new Sifra("gtshl", "101110");
		sifrarnik["gtshl"] = s;

		s = new Sifra("alshl", "111110");
		sifrarnik["alshl"] = s;

		s = new Sifra("eqshr", "001111");
		sifrarnik["eqshr"] = s;

		s = new Sifra("neshr", "011111");
		sifrarnik["neshr"] = s;

		s = new Sifra("gtshr", "101111");
		sifrarnik["gtshr"] = s;

		s = new Sifra("alshr", "111111");
		sifrarnik["alshr"] = s;

}

void Asembler::prvi(ifstream& fajl, int poc) {

	int rb = 0;
	string tekucaSekcija;
	int velicinaSekcije = 0;
	int trenutnaVrednost=0;
	bool imaps = false; //da li ima prethodne sekcije
	int poceci = poc;

	if (fajl.fail()) {
		cerr << "Ne postoji odgovarajuci fajl za citanje";
		exit(EXIT_FAILURE);
	}

	string red;
	std::getline(fajl, red);

	cout << "ime\t" << "rb \t" << "sekcija" << " vr. \t" << "l/g\t" << "flegovi "<<"vel.\t"<<"pocetak"<<"\n";
	
	while (red != ".end") {
		istringstream iss(red);
		string rec;

		while (iss >> rec) {

			if (rec == ".text" || rec == ".data" || rec == ".rodata" || rec == ".bss") {

				string ulaz=".";
				for (int i = 0; i < tekucaSekcija.length(); i++) { ulaz += tekucaSekcija.at(i); }

				if (imaps) {
					tabela[ulaz]->velicina = trenutnaVrednost;
					poceci += trenutnaVrednost;
				}
			
				Simbol* s = new Simbol(rec, ++rb);
				s->lokalnost = "l";
				s->vrednost = "0";
				s->pocetakSekcije = to_string(poceci);
				tabela[rec] = s;
				imaps = true;
				trenutnaVrednost = 0;

				if (rec == ".text") {
					s->flegovi = "ARX";
					s->sekcija = "text";
					tekucaSekcija = "text";
				}

				if (rec == ".data") {
					s->flegovi = "ARW";
					s->sekcija = "data";
					tekucaSekcija = "data";
				}

				if (rec == ".bss") {
					s->flegovi = "AW";
					s->sekcija = "bss";
					tekucaSekcija = "bss";
				}

				if (rec == ".rodata") {
					s->flegovi = "AR";
					s->sekcija = "rodata";
					tekucaSekcija = "rodata";
				}

				break;
			}

			if (regex_match(rec, regex(".*:.*"))) {

				std::size_t pos = rec.find(":");
				std::string str3 = rec.substr(0, pos);
				
				if (tabela[str3] != 0) {
					tabela[str3]->sekcija = tekucaSekcija;
					tabela[str3]->vrednost= to_string(trenutnaVrednost);
				}

				else {

					Simbol* s = new Simbol(str3, ++rb);
					s->flegovi = "/";
					s->lokalnost = "l"; 
					s->sekcija = tekucaSekcija;
					s->vrednost = to_string(trenutnaVrednost);
					tabela[str3] = s;
				}

				if (!(iss>>rec)) { break; }
			}
			

			if (rec == ".extern" || rec==".global") {

				while (iss >> rec) {

					int bz = 0; //bio zarez

					bool kraj = false;
					bool pz = false; // postoji zarez
					bool bzp = false;

					if (rec == ",") { continue; }
					for (unsigned i = 0; i < rec.length(); i++) {
						if (rec.at(i) == ',') {

							if (i == 0) {  pz = true; bzp = true; continue; }

							if (bzp) {
								bzp = false;
								std::string str3 = rec.substr(1, i-1);
								if (tabela[str3] != 0) {
									//tabela[str3]->sekcija = tekucaSekcija;
									//tabela[str3]->vrednost = trenutnaVrednost;
									tabela[str3]->lokalnost = "g";
								}
								else {
									Simbol* s = new Simbol(str3, ++rb);
									s->flegovi = "/";
									s->lokalnost = "g";
									tabela[str3] = s;
								}

								if (i + 1 != rec.length()) {
									bz = i + 1;
								}
								else { kraj = true; }
								
								continue;
							}

							pz = true;


							std::string str3 = rec.substr(bz, i-bz);
							if (tabela[str3] != 0) {
								//tabela[str3]->sekcija = tekucaSekcija;
								//tabela[str3]->vrednost = trenutnaVrednost;
								
								tabela[str3]->lokalnost = "g";
							}
							else {
								Simbol* s = new Simbol(str3, ++rb);
								s->flegovi = "/";
								s->lokalnost = "g";
								tabela[str3] = s;
							}
							if (i + 1 != rec.length()) {
								bz = i + 1; 
							}
							else {
								kraj = true;
							}
						}	
					}

					if (kraj) { continue; }

					if (bzp == true) {
						std::string str3 = rec.substr(1, rec.length() - 1);
						if (tabela[str3] != 0) {
							//tabela[str3]->sekcija = tekucaSekcija;
							//tabela[str3]->vrednost = trenutnaVrednost;
							tabela[str3]->lokalnost = "g";
						}
						else {
							Simbol* s = new Simbol(str3, ++rb);
							s->flegovi = "/";
							s->lokalnost = "g";
							tabela[str3] = s;
						}
						
						continue;
					}

					if (pz) {

						std::string str3 = rec.substr(bz, rec.length() - bz);
						if (tabela[str3] != 0) {
							//tabela[str3]->sekcija = tekucaSekcija;
							//tabela[str3]->vrednost = trenutnaVrednost;
							tabela[str3]->lokalnost = "g";
						}
						else {
							Simbol* s = new Simbol(str3, ++rb);
							s->flegovi = "/";
							s->lokalnost = "g";
							tabela[str3] = s;
						}
					}

					if (!pz) {
						if (tabela[rec] != 0) {
							//tabela[rec]->sekcija = tekucaSekcija;
							//tabela[rec]->vrednost = trenutnaVrednost;
							tabela[rec]->lokalnost = "g";
						}
						else {
							Simbol* s = new Simbol(rec, ++rb);
							s->flegovi = "/";
							s->lokalnost = "g";
							tabela[rec] = s;
						}
					}
				}
				break;
			}


			if (rec == ".skip") {
				iss >> rec;
				if (!jelibroj(rec)) { cerr << "Nije broj iza skip"; exit(EXIT_FAILURE); }
				trenutnaVrednost += stoi(rec);
				break;
			}

			if (rec == ".long") {
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					trenutnaVrednost += 4;
				}
				break;
			}

			if (rec == ".align") {
				iss >> rec;
				int delilac = stoi(rec);

				if ( !(delilac & (delilac - 1))==0) {
					cerr << "Kod .align poravnanje mora biti stepen dvojke \n";
					exit(EXIT_FAILURE);
				}

				int dopuna = delilac - (trenutnaVrednost % delilac);
				trenutnaVrednost += dopuna;
				break;
			}

			if (rec == ".char") {
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					trenutnaVrednost += 1;
				}
				break;
			}

			if (rec == ".word") {
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					trenutnaVrednost += 2;
				}
				break;
			}

			bool cetiri = true;
			string ins = rec;

			if (ins == "eqiret" || ins == "neiret" || ins == "gtiret" || ins == "aliret" || ins == "eqret" || ins == "neret" || ins == "gtret" || ins == "alret") {
				cetiri = false;
			}

			string sve;
			while (iss >> rec) {
				sve += rec;
			}

			istringstream novi(sve);
			string bez;

			
			while (getline(novi, bez, ',')) {
				if (regex_match(bez, regex("r[0-7]"))) {
					cetiri = false;
				}
				else {
					cetiri = true;
					break;
				}
			}

			if (!cetiri) {
				trenutnaVrednost += 2;
			}
			else {
				trenutnaVrednost += 4;
			}
			cetiri = true;
			break;
		}

		std::getline(fajl, red);
	}
	string ulaz = ".";
	for (int i = 0; i < tekucaSekcija.length(); i++) { ulaz += tekucaSekcija.at(i); }
	tabela[ulaz]->velicina = trenutnaVrednost;

	for (map<string, Simbol* >::const_iterator it = tabela.begin(); it != tabela.end(); ++it)
	{
		std::cout << it->second->ime << "\t" << it->second->rb <<"\t"<< it->second->sekcija <<"\t" << it->second->vrednost << "\t" << it->second->lokalnost << "\t" << it->second->flegovi<<"\t"<<it->second->velicina<<"\t"<<it->second->pocetakSekcije<<"\n";
		
	}
}


void Asembler::drugi(ifstream& fajl) {
	
	string ispisdata;
	string ispistext;
	string ispisrodata;

	string red;
	std::getline(fajl, red);

	string tekucaSekcija;
	int brojac = 0;

	while (red != ".end") {
		
		istringstream iss(red);
		string rec;

		bool labela = false;

		bool pcrel1 = false;

		while (iss >> rec) {

			if (rec == ".text" || rec == ".data" || rec == ".rodata" || rec == ".bss" ) {
				if (rec == ".text") tekucaSekcija = "text";
				if (rec == ".data") tekucaSekcija = "data";
				if (rec == ".rodata") tekucaSekcija = "rodata";
				if (rec == ".bss") tekucaSekcija = "bss";
				brojac = 0;
				break;
			}

			for (unsigned i = 0; i < rec.length(); i++) {
				if (rec.at(i) == ':') {
					labela = true;
				}
			}

			if (labela) {
				labela = false;
				if (!(iss >> rec)) { labela = false; break; }
			}

			if (rec == ".global") { while (iss >> rec) { continue; } continue; }

			if (rec == ".char") {
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					if (!jelibroj(bez)) { cerr << "char moze biti samo broj od 0 do 255"; exit(EXIT_FAILURE); }
					if (stoi(bez) < 0 || stoi(bez) > 255) { cerr << "char moze biti samo broj od 0 do 255"; exit(EXIT_FAILURE); }
					brojac += 1;
					string resenje = decuBin(stoi(bez), 8);
					if (tekucaSekcija == "text") {
						ispistext += resenje;
					}
					if (tekucaSekcija == "data") {
						ispisdata += resenje;
					}
					if (tekucaSekcija == "rodata") {
						ispisrodata += resenje;
					}
				}
				break;
			}

			if (rec == ".word") {
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					RelZapis* rz;
					bool bio = false;
					brojac += 2;
					string resenje;
					if (jelibroj(bez)) {
						
						int bb = stoi(bez);
						if (bb < 0) { 
							resenje = obrni(bitset<16>(bb).to_string(),16);
						}
						else {
							resenje = decuBin(stoi(bez), 16);
						}
					}
					else {
						/*if (jeliizraz(bez)) {
							jelivalidan(bez, brojac);
							//cerr << "izraz " + bez; exit(EXIT_FAILURE);
						}*/
						if (tabela[bez] == 0) {cerr<< "nepostojeca labela "+bez; exit(EXIT_FAILURE);}
						bio = true;
						string str = tabela[bez]->vrednost;
						rz = new RelZapis(to_string(brojac - 2), "PC_ABS", rbsekcije(bez));
						if (tabela[bez]->lokalnost == "g") { str = "0";  rz->vr = tabela[bez]->rb;}
						resenje = decuBin(stoi(str), 16);
					}
					if (tekucaSekcija == "text") {
						ispistext += resenje;
						if(bio)
						relzapisit.push_back(rz);
					}
					if (tekucaSekcija == "data") {
						ispisdata += resenje;
						if (bio)
						relzapisid.push_back(rz);
					}
					if (tekucaSekcija == "rodata") {
						ispisrodata += resenje;
						if (bio)
						relzapisir.push_back(rz);
					}
				}
				break;
			}

			if (rec == ".long") {
				RelZapis* rz;
				bool bio = false;
				string sve;
				while (iss >> rec) {
					sve += rec;
				}
				istringstream novi(sve);
				string bez;

				while (getline(novi, bez, ',')) {
					brojac += 4;
					string resenje;
					
					if (jelibroj(bez)) {
						long bb = stoi(bez);
						if (bb < 0) {
							resenje = obrni(bitset<32>(bb).to_string(),32);
						}
						else {
							resenje = decuBin(stoi(bez), 32);
						}
					}
					else {
						if (tabela[bez] == 0) { cerr << "nepostojeca labela " + bez; exit(EXIT_FAILURE); }
						bio = true;
						string str = tabela[bez]->vrednost;
						rz = new RelZapis(to_string(brojac - 4), "PC_ABS", rbsekcije(bez));
						if (tabela[bez]->lokalnost == "g") { str = "0"; rz->vr = tabela[bez]->rb;}
						resenje = decuBin(stoi(str), 32);
					}
					if (tekucaSekcija == "text") {
						ispistext += resenje;
						if (bio)
						relzapisit.push_back(rz);
					}
					if (tekucaSekcija == "data") {
						ispisdata += resenje;
						if (bio)
						relzapisid.push_back(rz);
						
					}
					if (tekucaSekcija == "rodata") {
						ispisrodata += resenje;
						if (bio)
						relzapisir.push_back(rz);
					}
				}
				break;
			}

			if (rec == ".skip") {
				iss >> rec;
				if (!jelibroj(rec)) { cout << "Posle skip mora ici broj \n"; exit(EXIT_FAILURE);
			}
				int broj = stoi(rec);
				brojac += broj;
				string resenje;
				for (int i = 0; i < broj; i++) {
					resenje+=decuBin(0, 8);
				}
				if (tekucaSekcija == "text") {
					ispistext += resenje;
				}
				if (tekucaSekcija == "data") {
					ispisdata += resenje;
				}
				if (tekucaSekcija == "rodata") {
					ispisrodata += resenje;
				}
				break;
			}

			if (rec == ".align") {
				iss >> rec;
				int delilac = stoi(rec);
				int dopuna = delilac - (brojac % delilac);
				brojac += dopuna;
				string resenje;

				for (int i = 0; i < dopuna; i++) {
					resenje += decuBin(0, 8);
				}
				if (tekucaSekcija == "text") {
					ispistext += resenje;
				}
				if (tekucaSekcija == "data") {
					ispisdata += resenje;
				}
				if (tekucaSekcija == "rodata") {
					ispisrodata += resenje;
				}
				break;
			}

			string sve;
			bool ret = false;
			if (rec == "alret") { rec = "alpop"; ret = true; }
			if (rec == "gtret") { rec = "gtpop"; ret = true; }
			if (rec == "eqret") { rec = "eqpop"; ret = true; }
			if (rec == "neret") { rec = "nepop"; ret = true; }

			bool jump = false;
			bool pcrel = false;
			string operand;
			if (rec == "aljmp" || rec == "eqjmp" || rec == "gtjmp" || rec == "nejmp") {
				jump = true;
				string ins = rec;
				iss >> operand;
				
				if (operand.at(0) == '$') { pcrel = true; }
				if (!pcrel) {
					if (ins == "aljmp") { rec = "almov";}
					if (ins == "gtjmp") { rec = "gtmov"; }
					if (ins == "eqjmp") { rec = "eqmov"; }
					if (ins == "nejmp") { rec = "nemov"; }
				}
				else {
					if (ins == "aljmp") { rec= "aladd"; }
					if (ins == "eqjmp") { rec= "eqadd"; }
					if (ins == "nejmp") { rec= "neadd"; }
					if (ins == "gtjmp") { rec= "gtadd"; }
				}
			}
			

			if (sifrarnik[rec] == 0) {
				cout << "Ne postoji takva instrukcija"<<rec;
				//break;
				exit(EXIT_FAILURE);
			}

			if (tekucaSekcija == "text") {
				ispistext += sifrarnik[rec]->kod;
			}

			if (tekucaSekcija == "data") {
				cerr << "u data ne mogu instrukcije"; exit(EXIT_FAILURE);
			}

			if (tekucaSekcija == "rodata") {
				cerr << "u rodata ne mogu instrukcije"; exit(EXIT_FAILURE);
			}

			if (tekucaSekcija == "bss") {
				cerr << "u bss ne mogu instrukcije"; exit(EXIT_FAILURE);
			}

			string ins = rec;

			brojac += 2;

			if (ins == "eqiret" || ins == "neiret" || ins == "gtiret" || ins == "aliret") {
				if (tekucaSekcija == "text") {
					ispistext += "0000000000";
					
				}
			}

			bool jedan = false;
			bool dva = true;
			bool samosrc = false;
			bool call = false;

			if (ins == "eqpop" || ins == "gtpop" || ins == "nepop" || ins == "alpop") {
				jedan = true;
				dva = false;
			}

			if (ins == "eqpush" || ins == "gtpush" || ins == "nepush" || ins == "alpush") {
				jedan = true;
				dva = false;
				samosrc = true;
			}

			if (ins == "eqcall" || ins == "gtcall" || ins == "necall" || ins == "alcall") {
				jedan = true;
				dva = false;
				samosrc = true;
				call = true;
			}

			
			if (!ret && !jump) {
				while (iss >> rec) {
					sve += rec;
				}
			}
			else {
				if(ret){ sve = "r7"; }
				if (jump && !pcrel) { sve = "r7," + operand; }
				if (jump && pcrel) {
					brojac += 2;
					string op1;
					for (int i = 1; i < operand.length(); i++) { op1 += operand.at(i); }
					operand = op1;
					ispistext += "0111100000";
					bool g = false;
					if (tabela[operand] == 0) { cerr << "nepostojeci operand";  exit(EXIT_FAILURE);}
					RelZapis* rz = new RelZapis(to_string(brojac-2), "PC_REL", rbsekcije(operand));
					if (tabela[operand]->lokalnost == "g") { ispistext += "1111111011111111"; g = true;  rz->vr = tabela[operand]->rb;}
					relzapisit.push_back(rz);
					bool mali = false;
					if (!g && tabela[operand]->vrednost == "0") { ispistext += "1111111011111111"; mali = true; }
					if (!g && tabela[operand]->vrednost == "1") { ispistext += "1111111111111111"; mali = true; }
					if (!g && !mali) { ispistext += decuBin(stoi(tabela[operand]->vrednost)-2, 16); }
					continue;
				}
			}
			istringstream novi(sve);
			string bez;

			bool trebadodati = false;
			int stadodati;
			int iteracija=0;
			string stavi;

			while (getline(novi, bez, ',')) {

				bool fleg = false; //oznacava je li r4[32]

				if (ins == "eqiret" || ins == "neiret" || ins == "gtiret" || ins == "aliret") {cerr << "iret nema operand"; exit(EXIT_FAILURE); }
				if (++iteracija == 2 && jedan) { cerr << "instrukcije push, pop i call imaju jedan operand"; exit(EXIT_FAILURE); }
				if (iteracija == 3) { cerr << "dva operanda je maksimum"; exit(EXIT_FAILURE); }
				if (regex_match(bez, regex("-{0,1}\\d+")) ) {
					if (call) { cerr << "call ne sme imati neposredno adresiranje"; exit(EXIT_FAILURE); }
					brojac += 2;
					int bb = stoi(bez);
					if (iteracija == 1 && !samosrc) { cerr << "dst ne sme biti neposredno adresiran"; exit(EXIT_FAILURE); }
					if (samosrc && jedan) { ispistext += "0000000000"; ispistext +=  obrni(bitset<16>(bb).to_string(),16);}
					if (dva) {
						//if (iteracija == 1) { trebadodati = true; stadodati = stoi(bez); }
						if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
						if (iteracija==2) { ispistext += "00000"; ispistext += obrni(bitset<16>(bb).to_string(),16);}
					}
					continue;
				}
				if (regex_match(bez, regex("r[0-7]"))) {
					if (dva) {
						ispistext += "01"; ispistext += kodZaRegistar(bez);
						continue;
					}
					if (jedan && !samosrc) { ispistext += "01"; ispistext += kodZaRegistar(bez)+"00000"; }
					if (jedan && samosrc) { ispistext += "0000001"; ispistext += kodZaRegistar(bez); }
					continue;
				}
				if (regex_match(bez, regex("[\\*]\\d+"))) {
					brojac += 2;
					string s = skiniPrvi(bez);
					if (jedan && samosrc) { ispistext += "0000010000"; ispistext += decuBin(stoi(s), 16); } 
					if (jedan && !samosrc) { ispistext += "1000000000";  ispistext += decuBin(stoi(s), 16);}
					if (dva) {
						if (iteracija == 1) { trebadodati = true; stadodati = stoi(s); ispistext += "10000";}
						if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije "; exit(EXIT_FAILURE); }
						if (iteracija == 2) { ispistext += "10000"; ispistext += decuBin(stoi(s), 16); }
					}
					continue;
				}
				if (regex_match(bez, regex("[\\&].+"))) {
					brojac += 2;
					if (call) { cerr << "call ne sme imati neposredno adresiranje"; exit(EXIT_FAILURE); }
					string s = skiniPrvi(bez);
					if (tabela[s] == 0) { cerr << "Nepostojeca labela: " << s;  exit(EXIT_FAILURE);}
					string vrednost = tabela[s]->vrednost;
					RelZapis* rz = new RelZapis(to_string(brojac-2), "PC_ABS", rbsekcije(s));
					if (tabela[s]->lokalnost == "g") { vrednost = "0"; rz->vr = tabela[s]->rb; }
					relzapisit.push_back(rz);
					if (iteracija == 1 && !samosrc) { cerr << "dst ne sme biti neposredno adresiran"; exit(EXIT_FAILURE); }
					if (jedan && samosrc) { ispistext += "0000000000"; ispistext += decuBin(stoi(vrednost), 16); }
					if (dva) {
						if (iteracija == 1) { trebadodati = true; stadodati = stoi(vrednost); ispistext += "00000";}
						if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
						if (iteracija == 2) { ispistext += "00000"; ispistext += decuBin(stoi(vrednost), 16); }
					}
					continue;
				}
				if (regex_match(bez, regex("r[0-7]\\[\\d+\\]"))) {
					brojac += 2;
					fleg = true;
					string registar;
					registar += bez.at(0);
					registar += bez.at(1);
					string b;
					for (int i = 3; i < bez.length() - 1; i++) { b += bez.at(i); }
					if (jedan && samosrc) { ispistext += "0000011"; ispistext += kodZaRegistar(registar); ispistext += decuBin(stoi(b), 16); }
					if (jedan && !samosrc) { ispistext += "11" + kodZaRegistar(registar)+"00000"+decuBin(stoi(b), 16); }
					if (dva) {
						if (iteracija == 1) { trebadodati = true; stadodati = stoi(b); ispistext += "11"+kodZaRegistar(registar);}
						if(iteracija==2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
						if (iteracija == 2) { ispistext += "11" + kodZaRegistar(registar)+ decuBin(stoi(b), 16); }
					}
					continue;
				}
				if (regex_match(bez, regex("r[0-7]\\[.+\\]")) && !fleg) {
					brojac += 2;
					string registar;
					registar += bez.at(0);
					registar += bez.at(1);
					string labela;
					for (int i = 3; i < bez.length() - 1; i++) { labela += bez.at(i); }
					if (tabela[labela] == 0) { cerr << "nepostojeci operand"<<bez; exit(EXIT_FAILURE); }
					string vrednost = tabela[labela]->vrednost;
					RelZapis* rz = new RelZapis(to_string(brojac-2), "PC_ABS", rbsekcije(labela));
					if (tabela[labela]->lokalnost == "g") { vrednost = "0"; rz->vr = tabela[labela]->rb;}
					relzapisit.push_back(rz);
					if (jedan && samosrc) { ispistext += "0000011" + kodZaRegistar(registar) + decuBin(stoi(vrednost), 16); }
					if (jedan && !samosrc) { ispistext += "11" + kodZaRegistar(registar) + "00000" + decuBin(stoi(vrednost), 16); }
					if (dva) {
						if (iteracija == 1) { trebadodati = true; stadodati = stoi(vrednost); ispistext += "11" + kodZaRegistar(registar); }
						if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
						if (iteracija == 2) { ispistext += "11" + kodZaRegistar(registar) + decuBin(stoi(vrednost), 16); }
					}
					continue;
				}

				string dodajpcrel;
				
				if (regex_match(bez, regex("\\$.+"))) {
					pcrel1 = true;
					brojac += 2;
					string labela;
					for (int i = 1; i < bez.length(); i++) { labela += bez.at(i); }
					if (tabela[labela] == 0) { cerr << "nepostojeci operand" << bez; exit(EXIT_FAILURE); }
					stavi = tabela[labela]->vrednost;
					bool stavljeno = false;
					if (stavi == "1") { stavi = "1111111111111111"; stavljeno = true; }
					if (stavi == "0") { stavi = "1111111011111111"; stavljeno = true; }
					if (!stavljeno) { stavi = decuBin(stoi(stavi)-2,16); }
					RelZapis* rz = new RelZapis(to_string(brojac-2), "PC_REL", rbsekcije(labela));
					if (tabela[labela]->lokalnost == "g") { stavi = "1111111011111111"; rz->vr = tabela[labela]->rb; }
					relzapisit.push_back(rz);
					if (jedan && samosrc) { ispistext += "0000011" + kodZaRegistar("r7") + stavi; }
					if (jedan && !samosrc) { ispistext += "11" + kodZaRegistar("r7") + "00000" + stavi; }
					if (dva) {
						if (iteracija == 1) { trebadodati = true; dodajpcrel = stavi; ispistext += "11" + kodZaRegistar("r7"); }
						if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
						if (iteracija == 2) { ispistext += "11" + kodZaRegistar("r7") + stavi; }
					}
					
					continue;
				}

				string labela = bez;
				brojac += 2;
				if (tabela[labela] == 0) { cerr << "nepostojeci operand"<<bez; exit(EXIT_FAILURE); }
				string vrednost = tabela[labela]->vrednost;
				RelZapis* rz = new RelZapis(to_string(brojac-2), "PC_ABS", rbsekcije(labela));
				if (tabela[labela]->lokalnost == "g") { vrednost = "0"; rz->vr = tabela[labela]->rb;}
				relzapisit.push_back(rz);
				if (jedan && samosrc) { ispistext += "0000010000"+decuBin(stoi(vrednost),16); }
				if (jedan && !samosrc) { ispistext += "1000000000" + decuBin(stoi(vrednost), 16); }
				if (dva) {
					if (iteracija == 1) { trebadodati = true; stadodati = stoi(vrednost); ispistext += "10000"; }
					if (iteracija == 2 && trebadodati) { cerr << "nedozvoljena velicina instrukcije"; exit(EXIT_FAILURE); }
					if (iteracija == 2) { ispistext += "10000" + decuBin(stoi(vrednost), 16); }
				}
			}

			if (trebadodati && !pcrel1) { ispistext += decuBin(stadodati, 16); }
			if (trebadodati && pcrel1) { ispistext += stavi; }
			

		}
		std::getline(fajl, red);
	}
	id = ispisdata;
	it = ispistext;
	ir = ispisrodata;
	cout << "\n#data \n"<<binuHeks(ispisdata)<<"\n";
	cout << "\n#text \n" << binuHeks(ispistext) << "\n \n";
	cout << "\n#rodata \n" << binuHeks(ispisrodata) << "\n \n";
	cout << "#rel text \n";
	cout << "ofset\t" << "tip\t\t" << "vr"<<"\n";
	for (int i = 0; i < relzapisit.size(); i++) {
		cout<<relzapisit[i]->ofset<<"\t"<<relzapisit[i]->tip<<"\t\t"<<relzapisit[i]->vr<<"\n";
	}
	cout << "\n#rel data \n";
	cout << "ofset\t" << "tip\t\t" << "vr" << "\n";
	for (int i = 0; i < relzapisid.size(); i++) {
		cout << relzapisid[i]->ofset << "\t" << relzapisid[i]->tip << "\t\t" << relzapisid[i]->vr << "\n";
	}
	cout << "\n#rel rodata \n";
	cout << "ofset\t" << "tip\t\t" << "vr" << "\n";
	for (int i = 0; i < relzapisir.size(); i++) {
		cout << relzapisir[i]->ofset << "\t" << relzapisir[i]->tip << "\t\t" << relzapisir[i]->vr << "\n";
	}
}

string Asembler::obrni(string resenje, int duzina) {
	if (duzina == 16) {
		string prva;
		string druga;
		for (int i = 0; i < 8; i++) {
			prva += resenje.at(i);
		}
		for (int i = 8; i < 16; i++) {
			druga += resenje.at(i);
		}
		resenje = druga + prva;

	}

	if (duzina == 32) {
		string prva;
		string druga;
		string treca;
		string cetvrta;
		for (int i = 0; i < 8; i++) {
			prva += resenje.at(i);
		}
		for (int i = 8; i < 16; i++) {
			druga += resenje.at(i);
		}
		for (int i = 16; i < 24; i++) {
			treca += resenje.at(i);
		}
		for (int i = 24; i < 32; i++) {
			cetvrta += resenje.at(i);
		}
		resenje = cetvrta + treca + druga + prva;
	}

	return resenje;
}

string Asembler::decuBin(int broj, int duzina) {

	string resenje;
	int r;

	while (broj != 0) { resenje = (broj % 2 == 0 ? "0" : "1") + resenje; broj /= 2; }

	if (resenje.length() != duzina) {
		int fali = duzina - resenje.length();
		string pom;
		for (int i = 0; i < fali; i++) {
			pom += "0";
		}
		pom += resenje;
		resenje = pom;
	}

	

	if (duzina == 16) {
		string prva;
		string druga;
		for (int i = 0; i < 8; i++) {
			prva += resenje.at(i);
		}
		for (int i = 8; i < 16; i++) {
			druga += resenje.at(i);
		}
		resenje = druga + prva;

	}

	if (duzina == 32) {
		string prva;
		string druga;
		string treca;
		string cetvrta;
		for (int i = 0; i < 8; i++) {
			prva += resenje.at(i);
		}
		for (int i = 8; i < 16; i++) {
			druga += resenje.at(i);
		}
		for (int i = 16; i < 24; i++) {
			treca += resenje.at(i);
		}
		for (int i = 24; i < 32; i++) {
			cetvrta += resenje.at(i);
		}
		resenje = cetvrta + treca + druga + prva;
	}

	return resenje;
}

string Asembler::binuHeks(string binarno)
{
	string resenje(""), pom, znak = "0000";
	int duzina = binarno.length() / 4;
	znak = znak.substr(0, duzina);
	//binarno = znak + binarno;
	for (int i = 0; i<binarno.length(); i += 4)
	{
		pom = binarno.substr(i, 4);
		if (!pom.compare("0000"))
		{
			resenje = resenje + "0";
		}
		else if (!pom.compare("0001"))
		{
			resenje = resenje + "1";
		}
		else if (!pom.compare("0010"))
		{
			resenje = resenje + "2";
		}
		else if (!pom.compare("0011"))
		{
			resenje = resenje + "3";
		}
		else if (!pom.compare("0100"))
		{
			resenje = resenje + "4";
		}
		else if (!pom.compare("0101"))
		{
			resenje = resenje + "5";
		}
		else if (!pom.compare("0110"))
		{
			resenje = resenje + "6";
		}
		else if (!pom.compare("0111"))
		{
			resenje = resenje + "7";
		}
		else if (!pom.compare("1000"))
		{
			resenje = resenje + "8";
		}
		else if (!pom.compare("1001"))
		{
			resenje = resenje + "9";
		}
		else if (!pom.compare("1010"))
		{
			resenje = resenje + "A";
		}
		else if (!pom.compare("1011"))
		{
			resenje = resenje + "B";
		}
		else if (!pom.compare("1100"))
		{
			resenje = resenje + "C";
		}
		else if (!pom.compare("1101"))
		{
			resenje = resenje + "D";
		}
		else if (!pom.compare("1110"))
		{
			resenje = resenje + "E";
		}
		else if (!pom.compare("1111"))
		{
			resenje = resenje + "F";
		}
		else
		{
			continue;
		}
	}
	
	return resenje;
}




