#include "tcalculator.h"

double TCalc::factorial(int n)
{
	if ( n == 0 || n == 1) return 1;
	return n*factorial(n-1);
}
int TCalc::priority(char op)
{
	switch ( op ){
		case '(': 
		case ')': return 0;
		case '+': 
		case '-': return 1;
		case '*': 
		case '/': return 2;
		case '^': return 3;
		case 's':
		case 'c': return 4;
		case '!': return 5;
		default: throw op;
	}
}
bool TCalc::Check()
{
	stc.Clear();

	string inf = '(' + infix + ')';
	for(unsigned int i = 0; i < inf.size(); i++)
	{
		if( inf[i] == '(' )
		{
			if ( inf[i+1] == '*' || inf[i+1] == '/' || inf[i+1] == '^') return false;
			if ( stc.isfull() ) throw i;
			stc.push('(');
		}
		if( inf[i] == ')' )
		{
			if(stc.isempty()) return false;
			else stc.pop();
		}
		if( inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '^' ){
			if ( inf[i+1] == ')' || inf[i+1] == '+' || inf[i+1] == '-' || inf[i+1] == '*' || inf[i+1] == '/' || inf[i+1] == '^' ) return false;
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
		if ( buf[i] == '(')	{
			stc.push(buf[i]);
			if ( buf[i+1] == '-' || buf[i+1] == '+' ) postfix += '0';
		}
		if ( buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.' || buf[i] == 'p' || buf[i] == 'e' )	{
			postfix += buf[i];
			if ( buf[i+1] == 'i' ) postfix += buf[++i];
		}
		if ( buf[i] == ')')
		{
			char el = stc.pop();
			while ( el != '(' )
			{
				postfix += el;
				el = stc.pop();
			}
		}
		if ( buf[i] == '!' || buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^' )
		{
			if ( buf[i] == '!' ) postfix += " 0";
			else  postfix += ' ';
			while( priority(buf[i]) <= priority(stc.top()) )
				postfix += stc.pop();
			stc.push(buf[i]);
		}
		if ( ( buf[i] == 's' && buf[i+1] == 'i' && buf[i+2] == 'n'  ) || ( buf[i] == 'c' && buf[i+1] == 'o' && buf[i+2] == 's'  ) )	{
		//	if ( buf[i+3] == '^' ) ;
			postfix += "0 ";
			while ( priority(buf[i]) <= priority(stc.top()) ) 
				postfix += stc.pop();
			stc.push(buf[i]);
		}
	}
}
double TCalc::Calc()
{
	stdub.Clear();

	for(unsigned int i = 0; i < postfix.size(); i++)
	{
		if ( postfix[i] == 's' || postfix[i] == 'c' || postfix[i] == '!' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' )
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
				case '!': res = factorial((int)op1) + op2; break;
				case 's': res = op1 + sin(op2); break;
				case 'c': res = op1 + cos(op2); break;
				default: throw postfix[i];
			}
			stdub.push(res);
		}
		if(postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.' || postfix[i] == 'p' || postfix[i] == 'e' )
		{
			if ( postfix[i] == 'e' ) stdub.push(M_E);
			else {
				if ( postfix[i+1] == 'i' ) stdub.push(M_PI);
				else {
					char* tmp;
					double res = strtod(&postfix[i], &tmp);
					int j = tmp - &postfix[i];
					i+= j - 1;
					stdub.push(res);
				}
			}
		}
	}
	return stdub.pop();
	if(!stdub.isempty()) throw stdub.pop();
}