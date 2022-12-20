#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *top = NULL;

// push
// pop
// top
// isEmpty
// print

void push(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = top;
	top = temp;
}

// void pop()
// {
// 	top = top->next;
// }
void pop()
{
	Node *temp = new Node();
	if (top == NULL)
		return;
	temp = top;
	top = temp->next;
	delete temp;
}

int Top()
{
	return top->data;
}

bool isEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void print()
{
	Node *temp = top;
	cout << "Stack:\n";
	while (temp != NULL)
	{
		cout << temp->data << "\n";
		temp = temp->next;
	}
	cout << "------------\n";
}

int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	pop();
	print();
	cout << Top() << "\n";
	cout << isEmpty() << "\n";
	return 0;
}
