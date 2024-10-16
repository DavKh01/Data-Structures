#include <iostream>
#include "graph.h"

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges with weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    std::cout << "Graph adjacency list:\n";
    g.print();

    std::cout << "\nBreadth First Search starting from vertex 0:\n";
    g.BFS(0);

    std::cout << "\nDepth First Search (Iterative) starting from vertex 0:\n";
    g.DFS_Iterative(0);

    std::cout << "\nDepth First Search (Recursive) starting from vertex 0:\n";
    g.DFS_Recursive(0);

    std::cout << "\nShortest path from vertex 0 to vertex 3:\n";
    std::vector<int> path = g.ShortestPath(0, 3);
    if (!path.empty()) {
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
    }
    else {
        std::cout << "No path found";
    }
    std::cout << std::endl;

    std::cout << "\nAll paths from vertex 0 to vertex 3:\n";
    g.getAllPaths(0, 3);

    std::cout << "\nCheck if the graph has a cycle (directed):\n";
    if (g.isCycledDirected()) {
        std::cout << "The graph has a cycle\n";
    }
    else {
        std::cout << "The graph does not have a cycle\n";
    }

    std::cout << "\nCheck if the graph has a cycle (undirected):\n";
    if (g.isCycledUndirected()) {
        std::cout << "The graph has a cycle\n";
    }
    else {
        std::cout << "The graph does not have a cycle\n";
    }

    std::cout << "\nTopological Sort (using DFS):\n";
    g.topSort();

    std::cout << "\nTopological Sort (using Kahn's algorithm):\n";
    g.topSortKahn();

    return 0;
}
