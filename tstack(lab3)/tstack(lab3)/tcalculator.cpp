#include "tcalculator.h"

int TCalc::priority(char op)
{
	int p = -1;

	switch ( op ){
		case '(': p = 0; break;
	//	case ')': p = 0; break;
		case '+': p = 1; break;
		case '-': p = 1; break;
		case '*': p = 2; break;
		case '/': p = 2; break;
		case '^': p = 3; break;
		default: throw p;
	}
	return p;
}
bool TCalc::Check()
{
	stc.Clear();

	for(unsigned int i = 0; i < infix.size(); i++)
	{
		if( infix[i] == '(' )
		{
			if ( stc.isfull() ) throw i;
			stc.push('(');
		}
		if( infix[i] == ')' )
		{
			if(stc.isempty()) return false;
			else stc.pop();
		}
	}
	if(!stc.isempty()) return false;
	else return true;
}
void TCalc::topostfix()
{
	stc.Clear();
	string buf = '(' + infix + ')';
	for(unsigned int i = 0; i < buf.size(); i++)
	{
		if( buf[i] == '(')	{
			stc.push(buf[i]);
			if( buf[i+1] == '-' ) postfix += '0';
		}
		if( buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.' ) postfix += buf[i];
		if( buf[i] == ')')
		{
			char el = stc.pop();
			while(el != '(')
			{
				postfix += el;
				el = stc.pop();
			}
		}
		if( buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^' )
		{
			postfix += ' ';
			while( priority(buf[i]) <= priority(stc.top()) )
				postfix += stc.pop();
			stc.push(buf[i]);
		}
	}
}
double TCalc::calc()
{
	stdub.Clear();

	for(unsigned int i = 0; i < postfix.size(); i++)
	{
		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' )
		{
			double res;
			double op2 = stdub.pop();
			double op1 = stdub.pop();
			switch (postfix[i]){
				case '+': res = op1 + op2; break;
				case '-': res = op1 - op2; break;
				case '*': res = op1 * op2; break;
				case '/': res = op1 / op2; break;
				case '^': res = pow(op1, op2); break;
				default: throw postfix[i];
			}
			stdub.push(res);
		}
		if(postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')
		{
			char* tmp;
			double res = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i+= j - 1;
			stdub.push(res);
		}
	}
	return stdub.pop();
	if(!stdub.isempty()) throw stdub.pop();
}