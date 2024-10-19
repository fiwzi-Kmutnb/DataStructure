#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

class Hashtable
{
public:
    Node *table[10];
    Hashtable()
    {
        for (int i = 0; i < 10; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(int a)
    {
        int key = a % 10;
        Node *newNode = new Node();
        newNode->data = a;
        if (table[key] == NULL)
        {
            table[key] = newNode;
        }
        else
        {
            Node *temp = table[key];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void del(int a)
    {
        int key = a % 10;
        Node *temp = table[key];
        if (temp->data == a)
        {
            table[key] = temp->next;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->data == a)
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
    }
    void find(int a)
    {
        int key = a % 10;
        Node *temp = table[key];
        while (temp != NULL)
        {
            if (temp->data == a)
            {
                cout << "Found" << endl;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Not Found" << endl;
    }
    void print(int a)
    {
        int key = a % 10;
        Node *temp = table[key];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Hashtable *ht = new Hashtable();
    char ch;
    int value = 0;
    while (true)
    {
        cin >> ch;
        switch (ch)
        {
        case 'i':
            cin >> value;
            ht->insert(value);
            break;
        case 'd':
            cin >> value;
            ht->del(value);
            break;
        case 'f':
            cin >> value;
            ht->find(value);
            break;
        case 'p':
            cin >> value;
            ht->print(value);
            break;
        default:
            return 0;
        }
    }
}