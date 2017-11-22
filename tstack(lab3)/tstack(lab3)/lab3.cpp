#include <iostream>
#include "tcalculator.h"
//#include "TStack.h"

using namespace std;

int main() {
	TCalc C;
	string expr;
	setlocale(LC_ALL, "Russian");

	cout << "������� ���������" << endl;
	while ( cin >> expr ){
		if ( expr == "exit" ) break;
		C.Setinfix(expr);
		if ( C.Check() )	{
			cout << "��������� ������� ���������." << endl;
			C.Setinfix(expr);
			C.topostfix();
		//	cout << C.Getpostfix() << endl; //����� ����������� ������ ���������
			double res = C.calc();
			cout << expr + " = "  << res << endl;
			cout << "--------------------------------------" << endl;
		}	else{
			cout << "��������� ������� �����������." << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	return 0;
}