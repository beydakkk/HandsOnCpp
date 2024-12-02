#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while (i <= high && arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);  // pivotu j. indisi yerleştir
    return j;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        cout << "Pivot " << arr[p] << " has moved to the index where it should be" << endl;
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }

}

int main(){
    vector<int> A = {10, 7, 8, 9, 1, 5};
    int N = A.size();
    cout << "Before:" << endl;
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl << endl;
    
    quickSort(A, 0, N - 1);
    cout << endl << "After:" << endl;
    for (auto i : A) {
        cout << i << " ";
    }
    return 0;
}