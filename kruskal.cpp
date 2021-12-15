#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
	vector<int> parent;
	vector<int> rank;

public:
	DSU(int n) {
		parent.resize(n, -1);
		rank.resize(n, 1);
	}

	int find(int i) {
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector<vector<int>> edgelist;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y});
	}

	int kruskals_mst() {
		sort(edgelist.begin(), edgelist.end());

		DSU s(V);
		int ans = 0;
		for(int i = 0; i < edgelist.size(); i++) {
			int w = edgelist[i][0];
			int x = edgelist[i][1];
			int y = edgelist[i][2];

			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
};

int main() {
	Graph g(7);
	g.addEdge(0, 1, 28);
	g.addEdge(0, 5, 10);
	g.addEdge(1, 2, 16);
	g.addEdge(1, 6, 14);
	g.addEdge(2, 3, 12);
	g.addEdge(3, 4, 22);
	g.addEdge(3, 6, 18);
	g.addEdge(4, 5, 25);
	g.addEdge(4, 6, 24);
	

	cout << g.kruskals_mst() << "\n";
	return 0;
}
