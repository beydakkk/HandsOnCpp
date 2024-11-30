#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;  // MAX-HEAP
    int heap_size;

    // Helper functions
    int parent(int i) {return i / 2;}
    int left(int i) {return 2 * i;}
    int right(int i) {return 2 * i + 1;}

    void heapify_up(int i){
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapify_down(int i){
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l <= heap_size && heap[l] > heap[largest])
            largest = l;

        if (r <= heap_size && heap[r] > heap[largest])
            largest = r;

        if (largest != i){
            swap(heap[i], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    PriorityQueue() : heap_size(0) {
        heap.push_back(-1);  // added -1 to 0th index for 1 based indexing
    }

    void insert(int key){
        heap_size++;
        if (heap_size >= heap.size())
            heap.push_back(key);
        else
            heap[heap_size] = key;
        heapify_up(heap_size);
    }

    int max(){
        if (heap_size < 1) 
            throw out_of_range("Priority queue is empty!");
        return heap[1]; // first element of the priority queue
    }

    int extract_max(){
        if (heap_size < 1)
            throw out_of_range("Priority queue is empty!");
        
        int max_val = heap[1];
        heap[1] = heap[heap_size];
        heap_size--;
        heapify_down(1);
        return max_val;
    }

    void increase_key(int i, int new_key){
        if (new_key < heap[i])
            throw invalid_argument("New key is smaller than current key");
    
        heap[i] = new_key;
        heapify_up(i);
    }

    int size(){
        return heap_size;
    }

    void printQueue(){
        for (int i = 1; i <= heap_size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(30);

    cout << "Queue: ";
    pq.printQueue();

    cout << "Max: " << pq.max() << endl;

    pq.increase_key(2, 25);
    cout << "Queue after increasing key at index 2: ";
    pq.printQueue();

    cout << "Extract Max: " << pq.extract_max() << endl;
    cout << "Queue after extract max: ";
    pq.printQueue();

    cout << "Size: " << pq.size() << endl;

    return 0;
}
