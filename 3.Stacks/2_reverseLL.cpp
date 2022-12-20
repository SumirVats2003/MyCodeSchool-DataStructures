// This is the program to reverse a string using a stack

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;

// inserting a node at the beginning of the list
void insert(int n)
{
	Node *temp = new Node();
	temp->data = n;
	temp->next = head;
	head = temp;
}

void display()
{
	Node *temp = head;
	cout << "Your list is:\n";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void reverse()
{
	if (head == NULL)
		return;
	stack<Node *> s;
	Node *temp = head;
	while (temp != NULL)
	{
		s.push(temp);
		temp = temp->next;
	}
	temp = s.top();
	head = temp;
	s.pop();
	while (!s.empty())
	{
		temp->next = s.top();
		s.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

int main()
{
	insert(2);
	insert(3);
	insert(5);
	insert(8);
	insert(9);
	display();
	reverse();
	display();
	return 0;
}
