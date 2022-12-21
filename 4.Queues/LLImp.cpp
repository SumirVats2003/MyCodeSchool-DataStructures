// This is the linked list implementation of queues

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

bool isEmpty()
{
	if (head == NULL && tail == NULL)
		return true;
	return false;
}

void enqueue(int x)
{
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (isEmpty())
	{
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void dequeue()
{
	Node *temp = head;
	if (head == NULL)
		return;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete temp;
}

int front()
{
	return head->data;
}

void print()
{
	Node *temp = head;
	cout << "Queue: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main()
{
	enqueue(2);
	print();
	cout << "Front: " << front() << "\n";
	enqueue(5);
	print();
	cout << "Front: " << front() << "\n";
	enqueue(6);
	print();
	cout << "Front: " << front() << "\n";
	enqueue(8);
	print();
	cout << "Front: " << front() << "\n";
	dequeue();
	print();
	cout << "Front: " << front() << "\n";
	return 0;
}
