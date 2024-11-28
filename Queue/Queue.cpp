#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;       
    int front;      // Index of the element at the front of the queue
    int rear;       // Index of the element at the end of the queue
    int capacity;   // Max capacity of queue
    int size;       // Number of elements in the queue

public:
    // Constructor
    Queue(int maxCapacity) {
        capacity = maxCapacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if(isFull()){
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " is added to queue." << endl;
    }

    void dequeue() {
        if(isEmpty()){
            cout << "Queue underflow!" << endl;
            return;
        }
        cout << arr[front] << " is removed from queue." << endl;
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

// Test
int main() {
    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); // Queue overflow

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue(); // Queue underflow

    return 0;
}
