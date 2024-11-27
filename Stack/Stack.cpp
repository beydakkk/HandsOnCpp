#include <iostream>
#include <stdio.h> 
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
    // in order to check if the stack has reached the limit. (isFull)
    int size;
    int maxSize;  

public:
    // Constructor
    Stack(int max){
        top = nullptr;
        size = 0;
        maxSize = max;
    }

    void push(int value){
        if(!isFull()){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
            size++;
            cout << value << " pushed to stack." << endl;
        }
        else
            return;
    }

    void pop(){
        if(isEmpty())
            return;
        Node* tmp = top;
        top = top->next;
        int poppedValue = tmp->data;
        delete tmp;
        size--;
        cout << poppedValue << " popped from stack.\n";
    }

    int peek(){
        if(isEmpty())
            return -444; // error
        return top->data;
    }

    bool isFull(){
        if(size == maxSize){
            cout << "Stack is full!" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top == nullptr){
            cout << "Stack is empty!" << endl;
            return true;
        }
        return false;
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main(){
    int maxSize = 3;
    Stack stack(maxSize);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top value: " << stack.peek() << endl;

    stack.push(40); // try to push when the stack is full

    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    stack.pop();
    stack.pop(); // try to pop when the stack is empty
    
    return 0;
}