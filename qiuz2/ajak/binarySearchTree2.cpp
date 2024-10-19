#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

int searchMax(Node* root){
	if (root->right != NULL) return searchMax(root->right);
	return root->key;

}


Node* deleteNode(Node* root, int key) {
	// 1. search for a node with key
	
	if (root == NULL){
	// 2. If the key is NOT Found, return without changing the tree
		cout << key << " is NOT FOUND\n";
		return root;
	} 
	
	if (root->key == key){
	// 3. If the key is Found, update its parent
		if (root->left == NULL && root->right==NULL){
			// 3.1 when the node has NO children
			cout << key << " has 0 child and deleted\n";
			return NULL;
		}
		
		if (root->left != NULL && root->right !=NULL){
			// 3.3 when the node has 2 children
			cout << key << " has 2 children and deleted\n";
			// step 1 search for a PREdecessor (max of Left subtree)
			int predecessor = searchMax(root->left);
			// step 2 replace key with predecessor
			root->key = predecessor;
			// step 3 delete the predecessor from left subtree
			root->left = deleteNode(root->left, predecessor);
			return root;
		}
		
		// 3.2 when the node has 1 child
		cout << key << " has 1 child and deleted\n";
		if (root->left != NULL) // only left child
			return root->left;
		else // only right child
			return root->right;
			
	}
	
	// Key is greater than root's key
    if (root->key < key)
        root->right = deleteNode(root->right, key);
	else    
	// Key is smaller than root's key
    	root->left = deleteNode(root->left, key);
    return root;
}


// function to search a key in a BST
Node* search(Node* root, int key) {
  
    // Base Cases: root is null or key 
    // is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

Node* insert(Node* root, int key) {
  
  	// Base case: root is null
	if (root == NULL) return new Node(key);
	
	if (key < root->key) {
		if (root->left == NULL) root->left = new Node(key);
		else insert(root->left, key);
	} else {
		if (root->right == NULL) root->right = new Node(key);
		else insert(root->right, key);
	}
	
	return root;
}

Node* insert2(Node* root, int key) {
  
  	// Base case: root is null
	if (root == NULL) return new Node(key);
	
	if (key < root->key) {
		root->left = insert(root->left, key);
	} else {
		root->right = insert(root->right, key);
	}
	
	return root;
}

void inorder(Node *root){
	if (root == NULL) return;
	
	inorder(root->left);
	cout << root->key << "  ";
	inorder(root->right);
}

void preorder(Node *root){
	if (root == NULL) return;
	
	cout << root->key << "  ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if (root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->key << "  ";
}



// Driver Code
int main() {
  
    Node* root = NULL;
	root = insert2(root, 50);
    root = insert2(root, 30);
    root = insert2(root, 70);
    root = insert2(root, 20);
    root = insert2(root, 60);

	root = deleteNode(root, 50);
//    
//    root = insert2(root, 40);
//    
//    root = insert2(root, 80);
  
//    (search(root, 19) != NULL)? cout << "Found\n": 
//                               cout << "Not Found\n";
//
//  
//    (search(root, 80) != NULL)? cout << "Found\n": 
//                               cout << "Not Found\n";
                               
    cout << "INORDER: " ;                          
    inorder(root);
    cout << endl;
    cout << "PREORDER: ";
    preorder(root);
    cout << endl;
    cout << "POSTORDER: ";
    postorder(root);
    cout << endl;

    return 0;
}
