#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 9

int minDistance(vector<int> distance, vector<bool> sptSet) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && distance[v] <= min)
			min = distance[v], min_index = v;

	return min_index;
}

void dijkstra(vector<vector<int>> graph, int src) {
	vector<int> distance(V, INT_MAX);

	vector<bool> sptSet(V, false);
	
	distance[src] = 0;

	for (int i = 0; i < V - 1; i++) {
		int u = minDistance(distance, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX
				&& distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
	}

	cout <<"Vertex \t Distance from Source\n";
	for (int i = 0; i < V; i++)
		cout << i << " \t\t" << distance[i] << "\n";
}

int main() {
	vector<vector<int>> graph = {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						         { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						         { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						         { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					        	 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						         { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						         { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						         { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						         { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

	dijkstra(graph, 0);

	return 0;
}