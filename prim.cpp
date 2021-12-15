#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 7

int minKey(vector<int> key, vector<bool> mstSet) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void primMST(vector<vector<int>> graph) {
	vector<int> parent(V);
	vector<int> key(V);
	
	vector<bool> mstSet(V);

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

    cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

int main() {
	vector<vector<int>> graph = {{ 0,  1,  5,  0,  0,  0,  0},
				     { 1,  0,  4,  8,  7,  0,  0},
			  	     { 5,  4,  0,  6,  0,  2,  0},
			             { 0,  8,  6,  0, 11,  9,  0},
				     { 0,  7,  0, 11,  0,  3, 10},
				     { 0,  0,  2,  9,  3,  0, 12},
				     { 0,  0,  0,  0, 10, 12,  0}};

	primMST(graph);

	return 0;
}
