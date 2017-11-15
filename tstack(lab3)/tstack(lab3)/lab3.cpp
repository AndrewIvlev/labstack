#include <iostream>
#include "tcalculator.h"
//#include "TStack.h"

using namespace std;

void main() {
	TCalc C;
	string inf = "2+3^3";

	cout << inf << endl;
	C.Setinfix(inf);
	C.Check();

	C.Setinfix(inf);
	C.topostfix();
	double res = C.calc();
	cout << res << endl;
}