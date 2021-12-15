#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m;
	
	vector<int> lArray(n1 + 1), rArray(n2 + 1);
	
	for (int i = 0; i < n1; i++)
        	lArray[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
        	rArray[j] = arr[m + 1 + j];

	lArray[n1] = INT_MAX;
	rArray[n2] = INT_MAX;

	int i = 0, j = 0;
	for(int k = l; k <= r; k++) {
		if(lArray[i] <= rArray[j]) {
			arr[k] = lArray[i];
			i++;
		}
		else {
			arr[k] = rArray[j];
			j++;
		}
	}
}

void mergeSort(vector<int>& arr, int begin, int end) {
	if (begin >= end) return;

	int mid = (begin + end) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}



int main() {
	vector<int> arr = {34, 98, 56, 26, 26, 58, 35, 10, 26, 73};
	int l = arr.size();
	
	cout << "Array before sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
    	cout << "\n";
    	
	mergeSort(arr, 0, l - 1);
	
	cout << "\nArray after sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
   	cout << "\n";
	return 0;
}
