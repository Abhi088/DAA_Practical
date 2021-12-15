#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int l) {
    for (int i = l / 2 - 1; i >= 0; i--)
        heapify(arr, l, i);

    for (int i = l - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {34, 98, 56, 26, 26, 58, 35, 10, 26, 73};
	int l = arr.size();
	
	cout << "Array before sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
    	cout << "\n";
    	
	heapSort(arr, l);
	
	cout << "\nArray after sorting \n";
	for (int i = 0; i < l; i++)
        	cout << arr[i] << " ";
   	cout << "\n";
	return 0;
}