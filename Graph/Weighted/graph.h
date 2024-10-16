#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
class Graph {
public:
    Graph(int n);
    void addVertex();
    void addEdge(int source, int destination, int weight);
    void BFS(int start) const;
    void DFS_Iterative(int start) const;
    void DFS_Recursive(int start) const;
    void print() const;
    void transpose();
    std::vector<int> ShortestPath(int start, int end) const;
    void getAllPaths(int start, int end) const;
    bool isCycledDirected() const;
    bool isCycledUndirected() const;
    int countConnectedComponents() const;
    void topSort();
    void topSortKahn();

private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

    void dfsHelper(int start, std::vector<bool>& visited) const;
    void allPathHelper(int start, int end, std::vector<int>& currentPath, std::vector<bool>& visited, std::vector<std::vector<int>>& allPaths) const;
    bool dfsisCycledDirected(int start, std::vector<bool>& visited, std::vector<bool>& recStack) const;
    bool dfsisCycledUndirected(std::vector<bool>& visited, int start, int parent) const;
    void dfstopSort(int start, std::vector<bool>& visited, std::stack<int>& s);
};
#endif