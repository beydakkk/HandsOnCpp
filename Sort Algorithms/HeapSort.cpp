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

void heapSort(vector<int>& A, int N){
    build_max_heap(A,N);
    for(int i = N; i >= 1; i--){
        swap(A[1], A[i]);
        max_heapify(A, 1, i-1);
    }
}


int main(){

    vector<int> A = {-1, 3, 5, 9, 6, -7, 8, 20, 10, 12, 0, 18, 9};  // 0th index holds dummy value.
    int N = A.size() - 1;

    cout << "Array before heap sort: " ;
    for (int i = 1; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    heapSort(A, N);

    cout << "Array after heap sort: ";
    for (int i = 1; i < N; i++)
        cout << A[i] << " ";

    return 0;
}