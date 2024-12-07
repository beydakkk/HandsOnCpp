#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited, topoStack);
    }
    topoStack.push(node);   // push the node to the stack after visiting all neighbors
}

vector<int> topologicalSort(const vector<vector<int>>& graph, int N) {
    stack<int> topStack;
    vector<bool> visited(N, false);

    // perform DFS for all unvisited nodes
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, topStack);
        }
    }

    // extract the nodes in topological order from the stack
    vector<int> topOrder;
    while (!topStack.empty()) {
        topOrder.push_back(topStack.top()); // push_back: appends to the end of the vector
        topStack.pop();
    }

    return topOrder;
}

int main() {
    // adjacency list
    vector<vector<int>> graph = {
        {1, 2}, // Node 0 points to 1, 2
        {3},    // Node 1 points to 3
        {3},    // Node 2 points to 3
        {}      // Node 3 has no outgoing edges
    };

    int N = graph.size();
    vector<int> topOrder = topologicalSort(graph, N);

    cout << "Topological Order: ";
    for (int node : topOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
