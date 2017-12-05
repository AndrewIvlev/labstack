#include <iostream>
#include "tcalculator.h"

using namespace std;

int main() {
	TCalc C;
	string expr;
	setlocale(LC_ALL, "Russian");

	cout << "������� ���������" << endl;
	while ( cin >> expr ){
		if ( expr == "exit" ) break;
		C.SetInfix(expr);
		if ( C.Check() )	{
			cout << "��������� ������� ���������." << endl;
			C.SetInfix(expr);
			C.topostfix();
			cout << "����������� ������ ���������: " << C.GetPostfix() << endl;
			double res = C.Calc();
			cout << expr + " = "  << res << endl;
			cout << "--------------------------------------" << endl;
			cout << "������� ���������" << endl;
		}	else	{
			cout << "��������� ������� �����������." << endl;
			cout << "--------------------------------------" << endl;
			cout << "������� ���������" << endl;
		}
		C.ClearPostfix();
	}
	return 0;
}