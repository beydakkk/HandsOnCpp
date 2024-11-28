#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper functions
    Node* insertNode(Node* root, int data) {
        if (root == nullptr) 
            return new Node(data);
        if (data < root->data) 
            root->left = insertNode(root->left, data);
        else 
            root->right = insertNode(root->right, data);
        
        return root;
    }

    Node* searchNode(Node* root, int data) {
        if (root == nullptr || root->data == data) 
            return root;

        if (data < root->data) 
            return searchNode(root->left, data);

        return searchNode(root->right, data);
    }

    Node* findMin(Node* root) {
        while (root && root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) 
            return root;

        if (data < root->data) 
            root->left = deleteNode(root->left, data);
        
        else if (data > root->data) 
            root->right = deleteNode(root->right, data);
        

        else {
            if (root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // If the tree has two children, find the smallest element of the sub-right network
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr){
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Main functions
    void insert(int data) {
        root = insertNode(root, data);
    }

    bool search(int data) {
        Node* result = searchNode(root, data);
        return result != nullptr;
    }

    void deleteValue(int data) {
        root = deleteNode(root, data);
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};



int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    bst.deleteValue(20);
    cout << "Inorder traversal (20 deleted): ";
    bst.inorder();

    bst.deleteValue(30);
    cout << "Inorder traversal (30 deleted): ";
    bst.inorder();

    return 0;
}