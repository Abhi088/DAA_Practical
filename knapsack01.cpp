#include <iostream>
#include <vector>

using namespace std;

struct Item {
	int w, v; // w for weight and v for value
	
	Item(int weight, int value) {
		this->w = weight;
		this->v = value;
	}
};

int knapSack01(int W, vector<Item> items, int n) {
	vector<vector<int>> K(2, vector<int> (W+1));
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i % 2][w] = 0;
			else if (items[i - 1].w <= w)
				K[i % 2][w] = max(items[i - 1].v + K[(i - 1) % 2][w - items[i - 1].w], K[(i - 1) % 2][w]);
			else
				K[i % 2][w] = K[(i - 1) % 2][w];
		}
	}
	return K[n % 2][W];
}

int main() {
	int W = 50;

	vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

	cout << knapSack01(W, items, items.size());

	return 0;
}
