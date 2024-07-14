#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>

int countComponentsBFS(std::vector<std::vector<int>>*graph){
    int numComponents = 0;
    std::vector<bool> visited;
    visited.resize(graph->size(), false);
    std::queue<int> curr;
    for(int i = 0; i<graph->size(); i++){
        if(!visited[i]){
            visited[i] = true;
            curr.push(i);
            numComponents++;
            std::cout<<i<<' ';
            while(!curr.empty()){
                int node = curr.front();
                curr.pop();
                for(int j = 0; j<(*graph)[node].size();j++){
                    int neighbour = (*graph)[node][j];
                    if(!visited[neighbour]){
                        curr.push(neighbour);
                        visited[neighbour] = true;
                        numComponents++;
                        std::cout<<neighbour<<" ";
                    }
                }
            }
        }
    }
    std::cout<<std::endl;
    return numComponents;
}   


int main() {
    std::vector<std::vector<int> > graph;
    graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}, {5}, {4}};
    int numComponents = countComponentsBFS(&graph);
    std::cout<<std::endl<<numComponents<<std::endl;
    return 0;
}
