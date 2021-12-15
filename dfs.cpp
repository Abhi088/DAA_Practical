#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
    map<int, bool> visited;
	map<int, list<int>> adj;

public:
	void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

	void DFS(int v) {
        visited[v] = true;
	    cout << v << " ";

	    list<int>::iterator i;
	    for (i = adj[v].begin(); i != adj[v].end(); ++i)
		    if (!visited[*i])
			    DFS(*i);
    }
};

int main() {
	Graph g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 8);
	g.addEdge(4, 3);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 3);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 6);
	g.addEdge(7, 9);
	g.addEdge(8, 1);
	g.addEdge(8, 7);
	g.addEdge(8, 9);

	cout << "Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}
