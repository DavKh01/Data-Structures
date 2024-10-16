#include "graph.h"

Graph::Graph(int n) : numVertices{ n }, adjList{}
{
	adjList.resize(numVertices);
}

void Graph::addVertex()
{
	++numVertices;
	adjList.resize(numVertices);
}

void Graph::addEdge(int source, int destination)
{
	if (source < 0 || destination < 0 || source >= numVertices || destination >= numVertices) {
		std::cout << "Invalid vertex index:\n";
		return;
	}
	adjList[source].push_back(destination);
}

void Graph::BFS(int start) const
{
	std::vector<bool> visited(numVertices, false);
	std::queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int k = q.front();
		std::cout << k << " ";
		q.pop();
		for (int v : adjList[k]) {
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
		s.pop();
		std::cout << k << " ";
		for (int v : adjList[k]) {
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
	for (int k : adjList[start]) {
		if (!visited[k]) {
			dfsHelper(k, visited);
		}
	}
}

void Graph::print() const
{
	for (int i = 0; i < numVertices; ++i) {
		std::cout << i << " -> ";
		for (int j : adjList[i]) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::transpose()
{
	std::vector<std::vector<int>> transposed(numVertices);
	for (int i = 0; i < numVertices; ++i) {
		for (int j : adjList[i]) {
			transposed[j].push_back(i);
		}
	}
	adjList = transposed;
}

std::vector<int> Graph::ShortestPath(int start, int end)
{
	std::vector<bool> visited(numVertices, false);
	std::vector<int> parent(numVertices, -1);
	std::queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == end) {
			std::vector<int> path;
			for (int i = end; i != -1; i = parent[i]) {
				path.insert(path.begin(), i);
			}
			return path;
		}
		for (int k : adjList[current]) {
			if (!visited[k]) {
				visited[k] = true;
				parent[k] = current;
				q.push(k);
			}
		}
	}
	return {};
}

void Graph::getAllPaths(int start, int end) const
{
	std::vector<bool> visited(numVertices, false);
	std::vector<std::vector<int>> allPaths;
	std::vector<int> currentPath;
	allPathHelper(start, end, currentPath, visited, allPaths);
	for (auto& path : allPaths) {
		for (int vertex : path) {
			std::cout << vertex << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::allPathHelper(int start, int end, std::vector<int>& currentPath, std::vector<bool>& visited, std::vector<std::vector<int>>& allPaths) const
{
	visited[start] = true;
	currentPath.push_back(start);
	if (start == end) {
		allPaths.push_back(currentPath);
	} else {
		for (int neighbour : adjList[start]) {
			if (!visited[neighbour]) {
				allPathHelper(neighbour, end, currentPath, visited, allPaths);
			}
		}
	}
	visited[start] = false;
	currentPath.pop_back();
}

bool Graph::isCycledDirected()
{
	std::vector<bool> visited(numVertices, false);
	std::vector<bool> recStack(numVertices, false);
	for (int i = 0; i < numVertices; ++i) {
		if (!visited[i] && dfsisCycledDirected(i, visited, recStack)) {
			return true;
		}
	}
	return false;
}

bool Graph::dfsisCycledDirected(int start, std::vector<bool>& visited, std::vector<bool>& recStack)
{
	visited[start] = true;
	recStack[start] = true;
	for (int i : adjList[start]) {
		if (!visited[i]) {
			if (dfsisCycledDirected(i, visited, recStack)) {
				return true;
			}
		} else if (recStack[i]) {
			return true;
		}
	}
	recStack[start] = false;
	return false;
}

bool Graph::isCycledUndirected()
{
	std::vector<bool> visited(numVertices, false);
	for (int i = 0; i < numVertices; ++i) {
		if (!visited[i] && dfsisCycledUndirected(visited, i, -1)) {
			return true;
		}
	}
	return false;
}

bool Graph::dfsisCycledUndirected(std::vector<bool>& visited, int start, int parent)
{
	visited[start] = true;
	for (int i : adjList[start]) {
		if (!visited[i]) {
			if (dfsisCycledUndirected(visited, i, start)) {
				return true;
			}
		} else if (i != parent) {
			return true;
		}
	}
	return false;
}

int Graph::DFS_ExtraCase() 
{
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

void Graph::topSort()
{
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

void Graph::dfstopSort(int start, std::vector<bool>& visited, std::stack<int>& s)
{
	visited[start] = true;
	for (int i : adjList[start]) {
		if (!visited[i]) {
			dfstopSort(i, visited, s);
		}
	}
	s.push(start);
}

void Graph::topSortKahn()
{
	if (isCycledDirected()) {
		std::cout << "Cycled Graph...\n";
		return;
	}
	std::vector<int> inDegree(numVertices, 0);
	for (int i = 0; i < numVertices; ++i) {
		for (int k : adjList[i]) {
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
		for (int k : adjList[n]) {
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