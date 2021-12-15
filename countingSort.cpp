#include<iostream>
#include<vector>

using namespace std;

void countingSort(vector<int>& arr, int size, int range) {
    vector<int> output(size), count(range + 1, 0);
 
    for (int i = 0; i < size; i++)
        count[arr[i]]++;
 
    for (int i = 1; i <= range; i++)
        count[i] += count[i - 1];
 
    for (int i = 0; i < size; i++) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

int main() {
	vector<int> arr = { 12,64,23,5,6,3,222,3,55,33 };
	int l = arr.size();
	countingSort(arr, l, 223);
	for(int i = 0; i < l; i++) cout << arr[i] << " ";
	return 0;
}
