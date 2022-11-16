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
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

bool IsOpeningParentheses(char C)
{
	if (C == '(' || C == '[' || C == '{')
		return true;

	return false;
}

bool IsClosingParentheses(char C)
{
	if (C == ')' || C == ']' || C == '}')
		return true;

	return false;
}

int GetOperatorValue(char C)
{
	int value = -1;
	switch (C)
	{
	case '*':
	case '/':
		value = 2;
	case '+':
	case '-':
		value = 1;
	}
	return value;

}

char HasHigherPrec(char top, char exp)
{
	int v1 = GetOperatorValue(top);
	int v2 = GetOperatorValue(exp);

	return v1 > v2 ? true : false;
}

std::string I2P(std::string exp)
{
	std::stack<char> s;
	std::string res = "";
	for (int i = 0; i <= exp.length(); i++)
	{
		if (IsOperand(exp[i]))
		{
			res = res + (exp[i]);
		}
		else if (IsOperator(exp[i]))
		{
			while (!s.empty() && !IsOpeningParentheses(s.top()) && HasHigherPrec(s.top(), exp[i]))
			{
				res = res + s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
		else if (IsOpeningParentheses(exp[i]))
		{
			s.push(exp[i]);
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
	while (!s.empty())
	{
		res = res + s.top();
		s.pop();
	}
	return res;
}

int main()
{
	std::string infix = "((a+b)*c-d)*e";
	std::string postfix = I2P(infix);

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