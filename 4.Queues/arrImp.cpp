// This is the circular array implementation of queues

#include <iostream>
using namespace std;

#define MAX_SIZE 101

template <typename T>
class Queue
{
private:
	T arr[MAX_SIZE];
	int front, rear;

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if (front == (rear + 1) % MAX_SIZE)
			return true;
		return false;
	}

	void enqueue(T x)
	{
		if (isFull())
			return;
		else if (isEmpty())
		{
			front = 0;
			rear = 0;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
		}
		arr[rear] = x;
	}

	void dequeue()
	{
		if (isEmpty())
			return;
		else if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}

	T Front()
	{
		if (!isEmpty())
			return arr[front];
		else
			return -1;
	}

	void print()
	{
		cout << "Queue: ";
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	Queue<int> Q;
	Q.enqueue(2);
	Q.enqueue(5);
	Q.enqueue(7);
	Q.enqueue(9);
	Q.print();
	Q.dequeue();
	Q.print();
}
