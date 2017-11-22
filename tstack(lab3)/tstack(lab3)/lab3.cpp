#include <iostream>
#include "tcalculator.h"
//#include "TStack.h"

using namespace std;

int main() {
	TCalc C;
	string expr;
	setlocale(LC_ALL, "Russian");

	cout << "Введите выражение" << endl;
	while ( cin >> expr ){
		if ( expr == "exit" ) break;
		C.Setinfix(expr);
		if ( C.Check() )	{
			cout << "Выражение введено корректно." << endl;
			C.Setinfix(expr);
			C.topostfix();
		//	cout << C.Getpostfix() << endl; //Вывод постфиксной записи выражения
			double res = C.calc();
			cout << expr + " = "  << res << endl;
			cout << "--------------------------------------" << endl;
		}	else{
			cout << "Выражение введено некорректно." << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	return 0;
}