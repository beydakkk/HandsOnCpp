#include <iostream>
#include <stdio.h> 
using namespace std;


class Node{
public:
    int data;
    Node* next;

    //Constructor
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* createCircularList(int n){
    Node* head = new Node(1);
    Node* curr = head;

    for(int i = 2; i <= n; i++){
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head; // in order to make the list circular

    return head;
}

int josephus(int n, int k){
    Node* head = createCircularList(n);
    Node* tmp = head;

    while(head->next != head){  // Loop until only one node is left
        for(int i = 0; i < k-1; i++){
            tmp = head;
            head = head->next;
        }
        tmp->next = head->next;
        delete head;
        head = tmp->next;
    }
    int survivor = head->data;
    delete head;
    return survivor;
}


int main() {
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    cout << "The survivor is person: " << josephus(n, k) << endl;
    return 0;
}