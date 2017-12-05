#include <iostream>
#include "tcalculator.h"

using namespace std;

int main() {
	TCalc C;
	string expr;
	setlocale(LC_ALL, "Russian");

	cout << "Введите выражение" << endl;
	while ( cin >> expr ){
		if ( expr == "exit" ) break;
		C.SetInfix(expr);
		if ( C.Check() )	{
			cout << "Выражение введено корректно." << endl;
			C.SetInfix(expr);
			C.topostfix();
			cout << "Постфиксная запись выражения: " << C.GetPostfix() << endl;
			double res = C.Calc();
			cout << expr + " = "  << res << endl;
			cout << "--------------------------------------" << endl;
			cout << "Введите выражение" << endl;
		}	else	{
			cout << "Выражение введено некорректно." << endl;
			cout << "--------------------------------------" << endl;
			cout << "Введите выражение" << endl;
		}
		C.ClearPostfix();
	}
	return 0;
}