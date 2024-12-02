#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int>& input){
    int N = input.size();
    int maxValue = 0;
    vector<int> output(N);

    for (int i = 0; i < N; i++)
        maxValue = max(maxValue, input[i]);
    vector<int> count(maxValue + 1, 0);

    for (int i = 0; i < N; i++)
        count[input[i]]++;

    for (int i = 1; i <= maxValue; i++)
        count[i] += count[i - 1];

    for (int i = N - 1; i >= 0; i--){
        output[count[input[i]] - 1] = input[i];
        count[input[i]]--;
    }
    return output;
}

int main(){
    vector<int> input = { 4, 3, 12, 1, 5, 5, 3, 9 };
    vector<int> output = countingSort(input);

    cout << "Original Array: " << endl;
    for(int i: input)
        cout << i << " ";
    cout << endl;

    cout << "Sorted Array: " << endl;
    for (int i : output)
        cout << i << " ";

    return 0;
}