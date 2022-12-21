#include <bits/stdc++.h>
using namespace std;

stack<char> S;

bool hasHigherPre(char x)
{
	char order[] = {'^', '*', '/', '+', '-'};
	int charIndex = 0;
	int topIndex = 0;
	for (int i = 0; i < 5; i++)
	{
		if (order[i] == x)
		{
			charIndex = i;
			break;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (order[i] == S.top())
		{
			topIndex = i;
			break;
		}
	}
	if (charIndex < topIndex)
		return true;
	return false;
}

char *infixToPostfix(char exp[])
{
	char res[101];
	int n = strlen(exp);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
		{
			while (!S.empty() && hasHigherPre(exp[i]))
			{
				res[++j] = S.top();
				S.pop();
			}
			S.push(exp[i]);
		}
		else
		{
			res[++j] = exp[i];
		}
	}
	while (!S.empty())
	{
		res[++j] = S.top();
		S.pop();
	}
	return res;
}

int perform(char op, int a, int b)
{
	switch (op)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case '^':
		return pow(a, b);
		break;
	default:
		break;
	}
	return 0;
}

int evaluatePostfix(char exp[])
{
	exp = infixToPostfix(exp);
	int n = strlen(exp);
	int op1, op2;
	int result;
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
		{
			op2 = S.top() - '0';
			S.pop();
			op1 = S.top() - '0';
			S.pop();
			result = perform(exp[i], op1, op2);
			S.push(result);
		}
		else
		{
			S.push(exp[i]);
		}
	}
	return S.top();
}

int main()
{
	char arr[101];
	cin >> arr;
	cout << evaluatePostfix(arr);
	return 0;
}

/*
  Infix to postfix conversion in C++
  Input Postfix expression must be in a desired format.
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

int main()
{
	string expression;
	cout<<"Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++.
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(IsOperator(expression[i]))
		{
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')')
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
*/
