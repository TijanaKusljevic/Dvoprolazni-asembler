#ifndef RELZAPIS_H
#define RELZAPIS_H

#include <string>
using namespace std;

class RelZapis {

	friend class Asembler;

public:
	RelZapis() {}
	RelZapis(string o, string t, int v) {
		ofset = o;
		tip = t;
		vr = v;
	}

private:
	string ofset;
	string tip;
	int vr;
};

#endif // !RELZAPIS_H