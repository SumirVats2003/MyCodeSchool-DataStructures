#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *head;

// inserting a node at the beginning of the list
void insert(int n)
{
	// In C
	// Node *temp = (Node *)malloc(sizeof(struct Node));
	Node *temp = new Node();
	// (*temp).data = n;
	temp->data = n;
	// temp->next = NULL;
	// if (head != NULL)
	// 	temp->next = head;
	temp->next = head;
	head = temp;
}

void insert(int x, int n)
{
	Node *temp1 = new Node();
	temp1->data = x;
	temp1->next = NULL;

	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	Node *temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void append(int x)
{
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	Node *temp2 = new Node();
	temp2 = head;

	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
}

void drop(int n)
{
	Node *temp = new Node();
	temp = head;
	if (n == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}

	for (int i = 0; i < n - 2; i++)
	{
		temp = temp->next;
	}
	Node *temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
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

int size()
{
	if (head == NULL)
		return 0;

	Node *temp = new Node();
	temp = head;
	int count = 1;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// iterative approach
void reverse()
{
	Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// next two functions implement recursion
void print(Node *p)
{
	if (p == NULL)
	{
		cout << "\n";
		return;
	}
	cout << p->data << " ";
	print(p->next);
}

void reversePrint(Node *p)
{
	if (p == NULL)
	{
		cout << "\n";
		return;
	}
	reversePrint(p->next);
	cout << p->data << " ";
}

void reverse(Node *p)
{
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	reverse(p->next);
	// Node *q = p->next;
	// q->next = p;
	p->next->next = p;
	p->next = NULL;
}

int main()
{
	head = NULL; // empty list
	// cout << "Enter the amount of numbers to be stored: ";
	// int n, x;
	// cin >> n;
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << "Enter value: ";
	// 	cin >> x;
	// 	insert(x);
	// 	display();
	// }
	insert(2, 1);
	insert(4, 2);
	insert(3, 1);
	insert(5, 2);
	insert(15, 2);
	insert(6, 2);
	insert(13, 2);
	append(10);
	drop(2);
	drop(4);
	cout << size() << "\n";
	// display();
	// reverse();
	// display();
	print(head);
	// reversePrint(head);
	reverse(head);
	display();
	return 0;
}
