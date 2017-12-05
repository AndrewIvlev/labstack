#include "tstack.h"
#include <string>
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
	void SetInfix(const string _inf){infix = _inf;}
	string GetInfix(){return infix;}
	string GetPostfix(){return postfix;}
	void ClearPostfix(){postfix = "";}
	bool Check();
	void topostfix();
	double Calc();
};