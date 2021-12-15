#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>& arr, int size) {
	for(int i = 0; i < size - 1; i++) {
		int min = i;
		for(int j = i + 1; j < size; j++) {
			if(arr[min] > arr[j]) min = j;
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	vector<int> arr = {38, 76, 49, 67, 19, 23, 64, 33, 49, 23, 12};
        int l = arr.size();
    
        cout << "Array before sorting \n";
        for(int i = 0; i < l; i++)
                cout << arr[i] << " ";
        cout << "\n";
        selectionSort(arr, l);
    
        cout << "\nArray after sorting \n";
        for(int i = 0; i < l; i++)
                cout << arr[i] << " ";
        cout << "\n";
        return 0;
}
