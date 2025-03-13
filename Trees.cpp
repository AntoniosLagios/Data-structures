//Binary tree implementation
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    return 0;
}
//Binary Search Tree (BST)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

// Search in BST
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

// Inorder Traversal (Sorted Order)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "Inorder Traversal (Sorted): "; 
    inorder(root); 
    cout << endl;

    int key = 7;
    cout << "Search " << key << ": " << (search(root, key) ? "Found" : "Not Found") << endl;

    return 0;
}
//Level Order Traversal (BFS using Queue)
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
//Deleting a Node in a BST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Find minimum node in right subtree
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete a node in BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Before Deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 5);
    
    cout << "After Deleting 5: ";
    inorder(root);
    cout << endl;

    return 0;
}
//Height of a Binary Tree
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to find height of tree
int findHeight(Node* root) {
    if (root == nullptr) return -1; // Height of empty tree is -1

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Height of the tree: " << findHeight(root) << endl;
    return 0;
}
//Checking if a Binary Tree is Balanced
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to check height balance
int checkBalance(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1; // Not balanced

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1; // Not balanced

    if (abs(leftHeight - rightHeight) > 1) return -1; // Unbalanced

    return max(leftHeight, rightHeight) + 1;
}

// Function to check if tree is balanced
bool isBalanced(Node* root) {
    return checkBalance(root) != -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7); // Makes it unbalanced

    if (isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is NOT balanced." << endl;

    return 0;
}
