#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int startNode, const vector<vector<int>>& graph){
    int N = graph.size();
    vector<bool> visited(N, false);
    queue<int> q;  // queue for bfs traversal

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    // Adjacency list
    vector<vector<int>> graph = {
        {1, 2}, // Neighbors of node 0
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}  // Neighbors of node 5
    };
    int startNode = 0;

    cout << "Adjacency list:" << endl;
    for(int i = 0; i < graph.size(); i++){
        cout << i << "->";
        for(int j : graph[i])
            cout << j << "->";
        cout << "/" << endl;
    }

    cout << endl << "BFS Traversal: " << endl;
    bfs(startNode, graph);

    return 0;
}
