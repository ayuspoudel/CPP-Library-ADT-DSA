#include<iostream>
#include<cstdlib>
#include<vector>

std::vector<int> dijkstra_algo(std::vector<std::vector<std::pair<int, int>>> graph, int source){
    int n = graph.size();
    std::vector<bool> visited;
    std::vector<int> distance;
    visited.resize(graph.size(), false);
    distance.resize(graph.size(), INT16_MAX);
    distance[source] = 0;
    for(int i = 0;i<n-1;i++){
        int min_distance = INT16_MAX;
        int curr_node = -1;
        for(int j =0; j<n-1;j++){
            if(!visited[j] && distance[j]<min_distance ){
                curr_node = j;
                min_distance = distance[j];
            }
        }
        for(auto neighbour : graph[curr_node]){
            int next_node = neighbour.first;
            int weight = neighbour.second;
            if(distance[curr_node]+ weight < distance[next_node]){
                distance[next_node] = distance[curr_node]+ weight;
            }
        }
    }
    return distance;
}

int main() {
    int n = 6, source = 0;
    std::vector<std::vector<std::pair<int, int>>> graph = {
        {{1, 4}, {2, 1}, {4, 3}},
        {{2, 2}, {3, 5}, {5, 1}},
        {{3, 1}, {4, 4}, {5, 3}},
        {{4, 2}, {5, 1}},
        {{5, 2}},
        {}
};