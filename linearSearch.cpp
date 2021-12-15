#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> arr, int target) {
	int l = arr.size();
	
	for(int i = 0; i < l; i++) {
		if(arr[i] == target) return i;
	}
	
	return -1;
}

int main() {
	vector<int> arr = {34, 98, 56, 86, 26, 58, 35, 10, 29, 73};
	int target = 26;
	
	int index = linearSearch(arr, target);
	
	if(index == -1) cout << "The element " << target << " was not found in the array.";
	else cout << "The element " << target << " was found at the index " << index << "\n";
	
	return 0;
}
