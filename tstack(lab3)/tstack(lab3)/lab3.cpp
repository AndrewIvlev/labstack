#include <iostream>
#include "tcalculator.h"
//#include "TStack.h"

using namespace std;

void main() {
	TCalc C;

	cout << "2*3+4" << endl;
	C.Setinfix("2*3+4");
	//C.Check();
	C.topostfix();
	double res = C.calc();
	cout << res << endl;
}