#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    char data;
    int freq;
    // binary tree structure
    Node* left;
    Node* right;

    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Priority queue (min-heap) için bir comparator oluşturuyoruz (overloading)
struct Compare {
    bool operator()(Node* left, Node* right){
        return left->freq > right->freq;
    }
};

// Preorder traversal
void printHuffmanCodes(Node* root, string str){
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << ": " << str << endl;
    }

    printHuffmanCodes(root->left, str + "0"); // sol alt ağaç
    printHuffmanCodes(root->right, str + "1"); // sağ alt ağaç
}


void huffmanCoding(const string& text){
    // frekansları hesaplama
    unordered_map<char, int> freq;
    for (char c : text) 
        freq[c]++;

    // min-heap (priority queue) oluşturma
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : freq)
        minHeap.push(new Node(pair.first, pair.second));  // pair.first: char, pair.second: freq
    

    // Huffman ağacını oluşturma
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    Node* root = minHeap.top();
    printHuffmanCodes(root, "");
}


int main() {
    string text = "eger buraya kadar geldiysen beni ise almalisin";
    cout << "Original Text: " << text << endl;

    cout << "Huffman Codes for characters: " << endl;
    huffmanCoding(text);

    

    return 0;
}