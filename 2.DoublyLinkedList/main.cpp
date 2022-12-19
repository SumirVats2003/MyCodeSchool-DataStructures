#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node *head;

Node *getNewNode(int d)
{
	Node *temp = new Node;
	temp->data = d;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertAtHead(int data)
{
	Node *temp = getNewNode(data);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void insertAtTail(int data)
{
	Node *newNode = getNewNode(data);
	Node *temp = head;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void print()
{
	Node *temp;
	temp = head;
	cout << "Forward: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void reversePrint()
{
	Node *temp = head;
	if (temp == NULL)
	{
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	cout << "Reverse: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << " ";
}

int main()
{
	head = NULL;
	insertAtHead(2);
	insertAtHead(4);
	insertAtHead(5);
	insertAtHead(6);
	insertAtTail(8);
	print();
	reversePrint();
	return 0;
}
