#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited){
    visited[node] = true;
    cout << node << " ";
    
    for(int neighbor : graph[node]){
        if(!visited[neighbor])
            dfs(neighbor, graph, visited);
    }
}



int main(){

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
    vector<bool> visited (graph.size(), false);

    cout << "Adjacency list:" << endl;
    for(int i = 0; i < graph.size(); i++){
        cout << i << "->";
        for(int j : graph[i])
            cout << j << "->";
        cout << "/" << endl;
    }

    cout << endl << "DFS Traversal: " << endl;
    dfs(startNode, graph, visited);

    return 0;
}