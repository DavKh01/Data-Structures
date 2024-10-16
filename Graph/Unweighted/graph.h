#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

class Graph
{
public:
    Graph(int n);
    void addVertex();
    void addEdge(int source, int dest);
    void BFS(int start) const;
    void DFS_Iterative(int start) const;
    void DFS_Recursive(int start) const;
    void print() const;
    void transpose();
    std::vector<int> ShortestPath(int start, int end);
    void getAllPaths(int src, int dest) const;
    bool isCycledDirected();
    bool isCycledUndirected();
    int DFS_ExtraCase();
    void topSort();
    void topSortKahn();
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    void dfsHelper(int start, std::vector<bool>& visit) const;
    void allPathHelper(int src, int dest, std::vector<int>& currPath, std::vector<bool>& visit, std::vector<std::vector<int>>& allPaths) const;
    bool dfsisCycledDirected(int source, std::vector<bool>& visit, std::vector<bool>& recstack);
    bool dfsisCycledUndirected(std::vector<bool>& visit, int source, int parent);
    void dfstopSort(int source, std::vector<bool>& visit, std::stack<int>& s);
};
#include "graph.cpp"
#endif      //GRAPH_H