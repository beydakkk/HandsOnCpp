#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left; // left child
    Node* right;  // right child

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// for sorting values in descending order
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left); 
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl << endl;

    return 0;
}
