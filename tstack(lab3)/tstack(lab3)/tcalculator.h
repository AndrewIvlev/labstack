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
	void Setinfix(const string _inf){infix = _inf;}
	string Getinfix(){return infix;}
	string Getpostfix(){return postfix;}
	bool Check();
	void topostfix();
	double calc();
};