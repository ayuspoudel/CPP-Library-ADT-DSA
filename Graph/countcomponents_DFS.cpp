#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>

std::vector<bool> visited;
std::stack<int> graphNodes;

void DFS(std::vector<std::vector<int>>& graph, int node) {
    visited[node] = true;
    graphNodes.push(node);
    std::cout << node << " ";
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            DFS(graph, neighbour);
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}, {5}, {4}};
    visited.assign(graph.size(), false); // Initialize visited array with the size of graph

    DFS(graph, 0); // Start DFS from node 0

    return EXIT_SUCCESS;
}
