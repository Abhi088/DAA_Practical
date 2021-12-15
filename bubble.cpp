#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& arr, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}
}

int main() {
	vector<int> arr = {34, 98, 56, 26, 26, 58, 35, 10, 26, 73};
	int l = arr.size();
	
	cout << "Array before sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
    	cout << "\n";
    	
	bubbleSort(arr, l);
	
	cout << "\nArray after sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
   	cout << "\n";
	return 0;
}
