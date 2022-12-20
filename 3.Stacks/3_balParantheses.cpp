#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> S;

bool pairsWithTop(char x)
{
	if (x == '(' && S.top() == ')')
		return true;
	else if (x == '[' && S.top() == ']')
		return true;
	else if (x == '{' && S.top() == '}')
		return true;
	else
		return false;
}

bool balancedParantheses(char exp[])
{
	int n = strlen(exp);
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			S.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !pairsWithTop(exp[i]))
			{
				return false;
			}
		}
		else
		{
			S.pop();
		}
	}
	return (S.empty()) ? true : false;
}

int main()
{
	char exp[101];
	cin >> exp;
	if (balancedParantheses(exp))
		cout << "Balanced\n";
	else
		cout << "Imbalanced\n";
	return 0;
}
