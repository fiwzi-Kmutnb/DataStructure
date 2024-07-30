#include <iostream>
using namespace std;

class Node
{
public:
	Node *next;
	Node *prev;
	int value;
	Node(int x)
	{
		value = x;
		next = NULL;
		prev = NULL;
	}
};

class Linklist
{
public:
	Node *list_head;
	bool isDelete = false; // บาป x5
	int valueDelete = 0;  // บาป x8
	Linklist(int x)
	{
		list_head = new Node(x);
		list_head->next = NULL;
	}
	void insertBefore(int i, int value)
	{
		if (value == valueDelete && isDelete == true) // บาป x4
		{
			isDelete = false; // บาป x4
			print(); // บาป x4
		}
		if (isExists(value))
			return;
		if (i == 0 || !isExists(i))
		{
			Node *h = new Node(value);
			Node *temp = list_head;
			while (true)
			{
				if (temp->next == NULL)
				{
					temp->next = h;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		else
		{
			Node *temp = list_head;
			Node *g = new Node(value);
			while (temp != NULL)
			{
				if (temp->value == i)
				{
					g->next = temp;
					list_head = g;
					break;
				}
				else if (temp->next->value == i)
				{
					g->next = temp->next;
					temp->next = g;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		if (isDelete) 
		{						 // บาป x6
			Delete(valueDelete); // บาป x7
		} // บาป x9
		print();
	}
	bool isExists(int value)
	{
		for (Node *h = list_head; h != NULL; h = h->next)
		{
			if (h->value == value)
				return true;
		}
		return false;
	}
	void insertAfter(int i, int value)
	{
		if (value == valueDelete && isDelete == true) // บาป x1
		{
			isDelete = false; // บาป x1
			print(); // บาป x1
		}
		if (isExists(value))
			return;

		if (i == 0 || !isExists(i))
		{
			Node *h = new Node(value);
			Node *temp = list_head;
			while (true)
			{
				if (temp->next == NULL)
				{
					temp->next = h;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		else
			for (Node *h = list_head; h != NULL; h = h->next)
			{
				if (h->value == i)
				{
					Node *g = new Node(value);
					g->next = h->next;
					h->next = g;
					break;
				}
			}
		if (isDelete) // บาป x1
		{						
			Delete(valueDelete); // บาป x1
		}
		print();
	}
	void Delete(int i)
	{
		if (list_head->value != NULL && list_head->next == NULL)
		{
			isDelete = true;				// บาป x1
			valueDelete = list_head->value; // บาป x2
			cout << " \n";					// บาป x2
			return;							// บาป x3
		}
		if (i == 0 || list_head->value == i)
		{
			list_head = list_head->next;
		}
		else
		{
			Node *temp = list_head;
			while (temp != NULL)
			{
				if (temp->next->value == i)
				{
					temp->next = temp->next->next;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		print();
	}
	void print()
	{
		// for(Node *h = list_head; h != NULL;h = h->next) {
		// 	cout << "Pointer: " << h << " Value: " << h->value << " Next: " << h->next << "\n";
		// }
		cout << "List: ";
		for (Node *h = list_head; h != NULL; h = h->next)
		{
			cout << h->value << " ";
		}
		cout << "\n";
	}
};

int main()
{
	char a;
	int index = 0, value = 0;
	cin >> a;
	cin >> value >> index;
	if (a == 'E')
		return 0;
	Linklist *lsr = new Linklist(value);
	lsr->print();
	while (true)
	{
		cin >> a;
		if (a == 'A')
		{
			index = 0, value = 0;
			cin >> value >> index;
			lsr->insertAfter(index, value);
		}
		if (a == 'I')
		{
			index = 0, value = 0;
			cin >> value >> index;
			lsr->insertBefore(index, value);
		}
		if (a == 'D')
		{
			index = 0;
			cin >> index;
			lsr->Delete(index);
		}
		if (a == 'E')
			break;
	}
	return 0;
}
