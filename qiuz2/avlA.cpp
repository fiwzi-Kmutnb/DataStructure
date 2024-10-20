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
        int height(Node *node) {
            if (node == NULL)
                return 0;
            return node->height;
        }
        int getBal(Node* node) {
            if(node == NULL)
                return 0;
            return height(node->left) - height(node->right);
        }
        Node* Rrotate(Node* n) {
            Node* y = n->left;
            Node* T2 = y->right;

            y->right = n;
            n->left = T2;

            n->height = max(height(n->left), height(n->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;

            return y;

        }
        Node* Lrotate(Node* n) {
            Node* y = n->right;
            Node* T2 = y->left;

            y->left = n;
            n->right = T2;

            n->height = max(height(n->left), height(n->right)) + 1;
            y->height = max(height(y->left),height(y->right)) + 1;

            return y;
        }
        
};
