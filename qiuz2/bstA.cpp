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


class BST {
    public:  
        Node *root;
        void add(int value) {
            if(root == NULL) 
                root = new Node(value);
            else {
                Node *cur = root;
                while(true) {
                    if(cur->data == value) 
                        break;
                    else if(cur->data > value) {
                        if(cur->left == NULL) {
                            cur->left = new Node(value);
                            break;
                        } else {
                            cur = cur->left;
                        }
                    } else {
                        if(cur->right == NULL) {
                            cur->right = new Node(value);
                            break;
                        } else {
                            cur = cur->right;
                        }
                    }
                }
            }
        }
        void remove(int value) {
            root = removeRecu(root, value);
        }
        void bfs() {
            if(root == NULL) 
                return;
            queue<Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node *cur = q.front();
                q.pop();
                cout << cur->data << " ";
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            cout << endl;
        }
    private:
        Node* removeRecu(Node* root, int value) {
            if(root == NULL)
                return root;
            if(value < root->data)
                root->left = removeRecu(root->left, value);
            else if(value > root->data)
                root->right = removeRecu(root->right, value);
            else {
                if(root->left == NULL) {
                    Node *temp = root->right;
                    delete root;
                    return temp;
                }
                if(root->right == NULL) {
                    Node *temp = root->left;
                    delete root;
                    return temp;
                }
                Node *temp = minV(root->right);
                root->data = temp->data;
                root->right = removeRecu(root->right,temp->data);
            }
        }
        Node* minV(Node *node) {
            Node *cur = node;
            while(cur && cur->left != NULL) {
                cur = cur->left;
            }
            return cur;
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
            bst->bfs();
            break;
        // case 'p':
        //     bst->pre(bst->root);
        //     break;
        // case 'i':
        //     bst->in(bst->root);
        //     break;
        // case 't':
        //     bst->post(bst->root);
        //     break;
        default:
            return 0;
        }
    }
    return 0;
}
