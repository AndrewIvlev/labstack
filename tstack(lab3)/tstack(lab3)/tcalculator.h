#include "tstack.h"
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class TCalc{
	string infix;
	string postfix;
	TStack<char> stc;
	TStack<double> stdub;
public:
	TCalc(){}
	~TCalc(){}
	int priority(char op);
	double factorial(int n);
	void SetInfix(const string _inf){infix = _inf;}
	string GetInfix(){return infix;}
	string GetPostfix(){return postfix;}
	void ClearPostfix(){postfix = "";}
	bool Check();
	void topostfix();
	double Calc();
};