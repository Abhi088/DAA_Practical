#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& arr, int size) {
	for(int i = 1; i < size; i++) {
		int j = i;
		while(j >= 0 && arr[j] < arr[j - 1]) {
			arr[j] = arr[j] + arr[j - 1];
			arr[j - 1] = arr[j] - arr[j - 1];
			arr[j] = arr[j] - arr[j - 1];
			j--;
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
    	
	insertionSort(arr, l);
	
	cout << "\nArray after sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
   	cout << "\n";
	return 0;
}
