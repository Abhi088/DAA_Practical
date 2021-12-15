#include <iostream>
#include <algorithm>

using namespace std;

struct Object {
	int v, w; //v for value and weight
	
	Object(int value, int weight) {
		this->v = value;
		this->w = weight;
	}
};

bool compareObject(struct Object a, struct Object b)
{
	double r1 = (double)a.v / (double)a.w;
	double r2 = (double)b.v / (double)b.w;
	return r1 > r2;
}

double fractionalKnapsack(int totalWeight, vector<Object> arr, int n) {
	sort(arr.begin(), arr.end(), compareObject);

	int currW = 0;
	double totalValue = 0.0;
	
	for (int i = 0; i < n; i++) {
		if (currW + arr[i].w <= totalWeight) {
			currW += arr[i].w;
			totalValue += arr[i].v;
		}

		else {
			int left = totalWeight - currW;
			totalValue += arr[i].v * ((double)left / (double)arr[i].w);
			break;
		}
	}

	return totalValue;
}

int main() {
	int W = 100;
	vector<Object> arr = {{20, 10}, {30, 20}, {66, 30}, {40, 40}, {60, 50}};

	cout << "Total value that can be accomodated in knapsack = " << fractionalKnapsack(W, arr, arr.size()) << "\n";
	return 0;
}
