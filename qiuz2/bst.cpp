#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    void add(int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (current->data == value)
                {
                    break;
                }
                else if (current->data > value)
                {
                    if (current->left == NULL)
                    {
                        current->left = new Node(value);
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->right == NULL)
                    {
                        cout << "right" << endl;
                        current->right = new Node(value);
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }
    void remove(int value)
    {
        root = removeRec(root, value);
    }
    void BreadthFirst()
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
        cout << endl;
    }
    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    void postOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
    void preOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

private:
    Node* removeRec(Node* root, int value)
    {
        if (root == NULL)
            return root;

        if (value < root->data)
            root->left = removeRec(root->left, value);
        else if (value > root->data)
            root->right = removeRec(root->right, value);
        else
        {
            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = removeRec(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};

int main()
{
    char key;
    int value;
    BST *bst = new BST();
    while (key != 'x')
    {
        cin >> key;
        switch (key)
        {
        case 'a':
            cin >> value;
            bst->add(value);
            break;
        case 'd':
            cin >> value;
            bst->remove(value);
            break;
        case 'b':
            bst->BreadthFirst();
            break;
        case 'p':
            bst->preOrder(bst->root);
            break;
        case 'i':
            bst->inOrder(bst->root);
            break;
        case 't':
            bst->postOrder(bst->root);
            break;
        default:
            return 0;
        }
    }
    return 0;
}
