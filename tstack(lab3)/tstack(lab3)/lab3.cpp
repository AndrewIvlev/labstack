#include <iostream>
#include "tcalculator.h"
//#include "TStack.h"

using namespace std;

int main() {
	TCalc C;
	string inf = "*5 + (-3)*(-2)";
	setlocale(LC_ALL, "Russian");

	C.Setinfix(inf);
	if ( C.Check() )
	{
		cout << "��������� ������� ���������." << endl;
		C.Setinfix(inf);
		C.topostfix();
	//	cout << C.Getpostfix() << endl; //����� ����������� ������ ���������
		double res = C.calc();
		cout << inf + " = "  << res << endl;
	}
	else cout << "��������� ������� �����������." << endl;

	return 0;
}