#include<iostream>
#include<vector>

using namespace std;

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int divide(vector<int>& arr, int l, int h) {
	int pivot = arr[h];
	int i = l - 1;
	
	for (int j = l; j < h; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high) {
		int divideIndex = divide(arr, low, high);

		quickSort(arr, low, divideIndex - 1);
		quickSort(arr, divideIndex + 1, high);
	}
}


int main() {
	vector<int> arr = {34, 98, 56, 26, 26, 58, 35, 10, 26, 73};
	int l = arr.size();
	
	cout << "Array before sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
    	cout << "\n";
    	
	quickSort(arr, 0, l - 1);
	
	cout << "\nArray after sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
   	cout << "\n";
	return 0;
}
