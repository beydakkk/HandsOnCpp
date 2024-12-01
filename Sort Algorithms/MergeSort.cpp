#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    vector<int> copy = arr;
    
    for(int k = low; k <= high; k++){
        if(i > mid){ // sol taraf bitmişse
            arr[k] = copy[j];
            j++;
            break;
        }
        if(j > high){ // sağ taraf bitmişse
            arr[k] = copy[i];
            i++;
            break;
        }
        if(copy[j] < copy[i]){  // sağdaki eleman soldakinden küçükse
            arr[k] = copy[j];
            j++;
        }
        else{  // soldaki eleman sağdakinden küçükse
            arr[k] = copy[i];
            i++;
        }
    }
}

void MergeSort(vector<int>& arr, int low, int high){
    if(low < high){
        int mid = low + (high- low) / 2;
        MergeSort(arr, low, mid);  // sol tarafı sırala
        MergeSort(arr, mid+1, high);  // sağ tarafı sırala
        Merge(arr, low, mid, high);
    }
}

int main(){

    vector<int> A = {1, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int low = 0;
    int high = A.size() - 1;

    cout << "Unordered array: ";
    for (int i : A)
        cout << i << " ";
    cout << endl;

    MergeSort(A, low, high);

    cout << "Ordered array: ";
    for(int i : A)
        cout << i << " ";
    
    return 0;
}