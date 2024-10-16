#include "graph.h"

Graph::Graph(int n) :numVertices{n}, adjList{}
{
    adjList.resize(numVertices);
}

void Graph::addVertex()
{
    ++numVertices;
    adjList.resize(numVertices);
}

void Graph::addEdge(int source, int destination, int weight)
{
    if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices) {
        std::cout << "Invalid vertex index \n";
        return;
    }
    adjList[source].emplace_back(destination,weight);
}

void Graph::BFS(int start) const
{
    std::vector<bool> visited(numVertices, false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        std::cout << k << " ";
        for (const auto& [v, weight] : adjList[k]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFS_Iterative(int start) const
{
    std::vector<bool> visited(numVertices, false);
    std::stack<int> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty()) {
        int k = s.top();
        std::cout << k << " ";
        s.pop();
        for (const auto& [v, weight] : adjList[k]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFS_Recursive(int start) const
{
    std::vector<bool> visited(numVertices, false);
    dfsHelper(start, visited);
    std::cout << std::endl;
}

void Graph::dfsHelper(int start, std::vector<bool>& visited) const
{
    visited[start] = true;
    std::cout << start << " ";
    for (const auto& [v, weight] : adjList[start]) {
        if (!visited[v]) {
            dfsHelper(v, visited);
        }
    }
}

void Graph::print() const
{
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << " -> ";
        for (const auto& [j, weight] : adjList[i]) {
            std::cout << "(" << j << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::transpose()
{
    std::vector<std::vector<std::pair<int, int>>> transposed(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        for (const auto& [j, weight] : adjList[i]) {
            transposed[j].emplace_back(i, weight);
        }
    }
    adjList = transposed;
}

std::vector<int> Graph::ShortestPath(int start, int end) const {
    std::vector<bool> visited(numVertices, false);
    std::vector<int> parent(numVertices, -1);
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (u == end) {
            std::vector<int> path;
            for (int i = end; i != -1; i = parent[i]) {
                path.insert(path.begin(), i);
            }
            return path;
        }
        if (visited[u]) continue;
        visited[u] = true;
        for (const auto& [v, weight] : adjList[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    return {}; // No path found
}

void Graph::getAllPaths(int start, int end) const {
    std::vector<bool> visited(numVertices, false);
    std::vector<std::vector<int>> allPaths;
    std::vector<int> currentPath;
    allPathHelper(start, end, currentPath, visited, allPaths);
    for (const auto& path : allPaths) {
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::allPathHelper(int start, int end, std::vector<int>& currentPath, std::vector<bool>& visited, std::vector<std::vector<int>>& allPaths) const {
    visited[start] = true;
    currentPath.push_back(start);
    if (start == end) {
        allPaths.push_back(currentPath);
    }
    else {
        for (const auto& [neighbour, weight] : adjList[start]) {
            if (!visited[neighbour]) {
                allPathHelper(neighbour, end, currentPath, visited, allPaths);
            }
        }
    }
    visited[start] = false;
    currentPath.pop_back();
}

bool Graph::isCycledDirected() const {
    std::vector<bool> visited(numVertices, false);
    std::vector<bool> recStack(numVertices, false);
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && dfsisCycledDirected(i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

bool Graph::dfsisCycledDirected(int start, std::vector<bool>& visited, std::vector<bool>& recStack) const {
    visited[start] = true;
    recStack[start] = true;
    for (const auto& [i, weight] : adjList[start]) {
        if (!visited[i]) {
            if (dfsisCycledDirected(i, visited, recStack)) {
                return true;
            }
        }
        else if (recStack[i]) {
            return true;
        }
    }
    recStack[start] = false;
    return false;
}

bool Graph::isCycledUndirected() const {
    std::vector<bool> visited(numVertices, false);
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && dfsisCycledUndirected(visited, i, -1)) {
            return true;
        }
    }
    return false;
}

bool Graph::dfsisCycledUndirected(std::vector<bool>& visited, int start, int parent) const {
    visited[start] = true;
    for (const auto& [i, weight] : adjList[start]) {
        if (!visited[i]) {
            if (dfsisCycledUndirected(visited, i, start)) {
                return true;
            }
        }
        else if (i != parent) {
            return true;
        }
    }
    return false;
}

int Graph::countConnectedComponents() const {
    std::vector<bool> visited(numVertices, false);
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            dfsHelper(i, visited);
            ++count;
        }
    }
    return count;
}

void Graph::topSort() {
    if (isCycledDirected()) {
        std::cout << "Cycled Graph...\n";
        return;
    }
    std::vector<bool> visited(numVertices, false);
    std::stack<int> s;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            dfstopSort(i, visited, s);
        }
    }
    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << std::endl;
}

void Graph::dfstopSort(int start, std::vector<bool>& visited, std::stack<int>& s) {
    visited[start] = true;
    for (const auto& [i, weight] : adjList[start]) {
        if (!visited[i]) {
            dfstopSort(i, visited, s);
        }
    }
    s.push(start);
}

void Graph::topSortKahn() {
    if (isCycledDirected()) {
        std::cout << "Cycled Graph...\n";
        return;
    }
    std::vector<int> inDegree(numVertices, 0);
    for (int i = 0; i < numVertices; ++i) {
        for (const auto& [k, weight] : adjList[i]) {
            ++inDegree[k];
        }
    }
    std::queue<int> q;
    for (int i = 0; i < numVertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> result;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        result.push_back(n);
        for (const auto& [k, weight] : adjList[n]) {
            --inDegree[k];
            if (inDegree[k] == 0) {
                q.push(k);
            }
        }
    }
    if (result.size() != numVertices) {
        std::cout << "Cycled Graph...\n";
        return;
    }
    for (int i : result) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}