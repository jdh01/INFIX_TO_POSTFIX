#include <iostream>
#include <stack>
#include <string>

bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

bool IsOpeningParentheses(char sym)
{

}

bool IsClosingParentheses(char sym)
{

}

char HasHigherPrec(const char* sym, char exp)
{

}

const char* I2P(const char* exp)
{
	std::stack<const char*> s;
	const char* res;
	int n = sizeof(exp);
	for (int i = 0; i <= n; i++)
	{
		if (IsOperator(exp[i]))
		{
			res = res + (exp[i]);
		}
		else if (IsOperand(exp[i]))
		{
			while (!s.empty() && !IsOpeningParentheses(s.top()) && HasHigherPrec(s.top(), exp[i]))
			{
				res = res + s.top();
				s.pop();
			}
		}
		else if (IsOpeningParentheses(exp[i]))
		{
			s.push();
		}
		else if (IsClosingParentheses(exp[i]))
		{
			while (!s.empty() && !IsOpeningParentheses(s.top()))
			{
				res = res + s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty)
	{
		res = res + s.top();
		s.pop();
	}
	return res;
}

int main()
{
	const char* infix = "(a+b)*c";
	const char* postfix = I2P(infix);

	std::cout << postfix << std::endl;
}

//Sude code - without dealing with parentheses 
/*
	I2P(exp)
	{
	Create a stack s
	for i = 0 to length of (exp-1)
	{
		if exp[i] is operand
			res = res + exp[i]
		else if exp[i] is operator
		{
			while(!S.empty() && !IsOpeningParentheses(s.top) && HasHigherPrec(s.top(), exp[i]))
			{
				res = res + s.top()
				s.pop
			}
			s.push
		}
		else if (IsOpeningParentheses(exp[i])
			s.push()
		else if	(IsClosingParentheses(exp[i])
		{
			while (!s.empty() && !IsOpeningParentheses(s.top))
			{
				res = res + s.top()
				s.pop()
			}
			s.pop()
		}
	}
	while(!s.empty)
	{
		res = res + s.top()
		s.pop()
	}
	return res
	}

*/