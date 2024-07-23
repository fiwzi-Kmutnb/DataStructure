#include <iostream>
#define ASIZE 10000
using namespace std;

class Queues
{
public:
	int range = -1;
	int front = 0;
	int size = 10;
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
		//			cout << (range % ASIZE) - front << "\n";
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
			//				cout <<  (ASIZE - 1) - (range % ASIZE) << " " << (range % ASIZE) << "\n";
			//				cout << range % ASIZE << " " << data << "\n";
			Array[range] = data;
		}
		//			else {
		//				cout << "FULL\n";
		//			}
	}
	int dequeue()
	{
		if (!isEmpty())
		{
			return Array[front++];
		}
		return -1;
	}
	void print()
	{
		//			int a = (range % ASIZE);
		//			cout << a << "\n";
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
