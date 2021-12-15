#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        list<int>::iterator i;

        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 2);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 5);
    g.addEdge(6, 8);
    g.addEdge(7, 0);
    g.addEdge(7, 6);
    g.addEdge(7, 8);

    cout << "Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
