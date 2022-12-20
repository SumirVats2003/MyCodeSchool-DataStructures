// This is the program to reverse a string using a stack

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

#define MAX_SIZE 101

int A[MAX_SIZE];
int TOP = -1;

void push(char x)
{
	if (TOP == MAX_SIZE - 1)
	{
		cout << "Error: Stack Overflow\n";
		return;
	}
	A[++TOP] = x;
}

void pop(void)
{
	if (TOP == -1)
	{
		cout << "Error: Stack Underflow\n";
		return;
	}
	TOP--;
}

int top(void)
{
	return A[TOP];
}

bool isEmpty(void)
{
	if (TOP == -1)
		return true;
	return false;
}

void print(void)
{
	cout << "The stack is: \n";
	for (int i = TOP; i >= 0; i--)
	{
		cout << A[i] << "\n";
	}
	cout << "--------------\n";
}

void reverse(char c[], int n)
{
	stack<char> s;
	for (int i = 0; i < n; i++)
	{
		s.push(c[i]);
	}

	for (int i = 0; i < n; i++)
	{
		c[i] = s.top();
		s.pop();
	}

	cout << "Reversed string: ";
	for (int i = 0; i < n; i++)
	{
		cout << c[i];
	}
}

int main()
{
	char C[51];
	cout << "Enter string: ";
	cin >> C;
	reverse(C, strlen(C));
	return 0;
}
