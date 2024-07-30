#include <iostream>
#define ASIZE 10000
using namespace std;

class Queues
{
public:
	int range = -1;
	int front = 3;
	int size = 5;
	int Array[ASIZE];
	bool isEmpty()
	{
		if (front > range)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (range - front == size - 1)
		{
			return true;
		}
		return false;
	}
	void enqueue(int data)
	{
		if (!isFull())
		{
			range++;
			Array[range % ASIZE] = data;
		}
		else
		{
			cout << "FULL\n";
		}
	}
	int dequeue()
	{
		if (!isEmpty())
		{
			front++;
			return Array[(front % ASIZE) - 1];
		}
		return -1;
	}
	void print()
	{
		for (int i = front; i <= range; i++)
		{

			cout << Array[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	Queues d;
	char t;
	int u = 0;
	while (true)
	{

		cin >> t;
		if (t == 'e')
		{
			cin >> u;
			d.enqueue(u);
		}
		if (t == 'd')
		{
			cout << d.dequeue() << "\n";
		}
		if (t == 'p')
		{
			d.print();
		}
		if (t == 'n')
		{
			cout << (d.range - d.front) + 1 << "\n";
		}
		if (t == 's')
		{
			cout << d.Array[d.front] << " " << d.Array[d.range] << "\n";
		}
		if (t == 'x')
		{
			break;
		}
	}
	return 0;
}
