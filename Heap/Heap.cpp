#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector<int>& A, int i, int N){
    int left = 2*i;  // left child
    int right = 2*i + 1;  // right child
    int largest = i;
    if(left <= N && A[left] > A[largest])
        largest = left;
    if(right <= N && A[right] > A[largest])
        largest = right;
    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        max_heapify(A, largest, N);
    }

}

void build_max_heap(vector<int>& A, int N){
    for(int i = N/2; i >= 1; i--){  // 1-N/2 : parent nodes, N/2-N : leaf nodes
        max_heapify(A, i, N);
    }
}


int main() {
    // we use 1-based indexing, so 0.th index in the vector has a dummy value (-1)
    vector<int> A = {-1, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int N = A.size() - 1;
    cout << "Array (before heapify): ";
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    build_max_heap(A, N);
    cout << "Max-Heap: ";
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}