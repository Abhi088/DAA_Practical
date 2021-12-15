#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
	int l = 0, h = arr.size() - 1, mid;
	while(l <= h) {
		mid = (l + h) / 2;
		if(arr[mid] == target) return mid;
		else if(arr[mid] > target) h = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int main() {
	vector<int> arr = { 3, 3, 5, 6, 8, 10, 23, 45, 66, 77, 89 };
	int l = arr.size();
	int target = 23;
	
	int searchIndex = binarySearch(arr, target);
	
	if(searchIndex == -1) cout << "Element " << target << " not found in the array";
	else {
		cout << "The element " << target << " in the array ";
		for(int i = 0; i < l; i++) cout << arr[i] << " ";
		cout << " is found at index " << binarySearch(arr, target) << "\n";
	}
	
	return 0;
}
