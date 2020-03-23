#include "TPolinom.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

int main() {

	/*int a[2][2];
	for (int i = 0; i < 2; i++) {
		cin >> a[i][0];
		cin >> a[i][1];
	}*/

	TMonom g;
	g.coeff = 5;
	g.px = 1;
	g.py = 1;
	g.pz = 1;
	TPolinom p;
	cout << "enter coeff, px, py, pz" << endl;
	while (g.coeff) {
		cin >> g.coeff;
		cin >> g.px;
		cin >> g.py;
		cin >> g.pz;
		p.insOrd(g);
	}
	cout << "Polinom: " << p << endl;
	TPolinom q(p);
	TMonom m;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	p *= m;
	cout << "Polinom * Monom 5xyz: " << p << endl;
	p += q;
	cout << "Polinom * Monom 5xyz + Polinom: " << p << endl;
	q *= 2;
	cout << "Polinom * 2: " << q << endl;
	q -= p;
	cout << "Polinom * 2 - (Polinom * Monom 5xyz + Polinom): " << q << endl;



	_getch();

	return 0;
}
