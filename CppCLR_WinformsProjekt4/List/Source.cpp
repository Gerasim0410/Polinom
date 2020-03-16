#include <time.h>
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
	while (g.coeff) {
		cin >> g.coeff;
		cin >> g.px;
		cin >> g.py;
		cin >> g.pz;
		p.insOrd(g);
	}
	TPolinom res, q(p);
	TMonom m;
	m.coeff = 5;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	p *= m;
	p.insOrd(m);

	cout << res << endl;
	cout << q << endl;
	cout << p << endl;
	cout << m << endl;
	p += p;
	cout << p << endl;
	res = p*q;
	cout << res << endl;
	cout << q << endl;
	p *= 2;
	res -= p;
	cout << res << endl;
	res *= 2;
	cout << res << endl;



	_getch();

	return 0;
}
