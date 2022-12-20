#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101

template <typename T>

class Stack
{
private:
	T A[MAX_SIZE];
	int TOP;

public:
	Stack()
	{
		this->TOP = -1;
	}

	void push(T x)
	{
		if (this->TOP == MAX_SIZE - 1)
		{
			cout << "Error: Stack Overflow\n";
			return;
		}
		this->A[++this->TOP] = x;
	}

	void pop(void)
	{
		if (this->TOP == -1)
		{
			cout << "Error: Stack Underflow\n";
			return;
		}
		this->TOP--;
	}

	int top(void)
	{
		return this->A[this->TOP];
	}

	bool isEmpty(void)
	{
		if (this->TOP == -1)
			return true;
		return false;
	}

	void print(void)
	{
		cout << "The stack is: \n";
		for (int i = this->TOP; i >= 0; i--)
		{
			cout << this->A[i] << "\n";
		}
		cout << "--------------\n";
	}
};

int main()
{
	Stack<int> s;
	s.push(2);
	s.push(5);
	s.push(7);
	s.push(10);
	s.push(15);
	s.print();
	s.pop();
	s.print();
	return 0;
}
