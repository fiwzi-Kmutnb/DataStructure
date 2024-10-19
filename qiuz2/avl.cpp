#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVL {
private:
    Node *root;

    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int getBalance(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, int data) {
        if (node == NULL)
            return new Node(data);

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else if (data > node->data)
            node->right = insertNode(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == NULL)
            return root;

        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if(data > root->data)
            root->right = deleteNode(root->right, data);
        else {
            if((root->left == NULL) || (root->right == NULL)) {
                Node *temp = root->left ? root->left : root->right;

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

public:
    AVL() : root(NULL) {}

    void add(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void BreadthFirst() {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl;
    }

    void inOrder(Node* node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void preOrder(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    char key;
    int value;
    AVL *avl = new AVL();
    while (key != 'x') {
        cin >> key;
        switch (key) {
            case 'a':
                cin >> value;
                avl->add(value);
                break;
            case 'd':
                cin >> value;
                avl->remove(value);
                break;
            case 'b':
                avl->BreadthFirst();
                break;
            case 'p':
                avl->preOrder(avl->getRoot());
                cout << endl;
                break;
            case 'i':
                avl->inOrder(avl->getRoot());
                cout << endl;
                break;
            case 't':
                avl->postOrder(avl->getRoot());
                cout << endl;
                break;
            default:
                return 0;
        }
    }
    delete avl;
    return 0;
}