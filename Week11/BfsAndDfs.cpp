/*
BFS algorithm for graph traversal
DFS algorithm for graph traversal
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// Time Complexity: O(V + E)
void bfs(int start, unordered_map<int, unordered_set<int>>& graph) {
	queue<int> q;
	q.push(start);
	unordered_set<int> visited;
	visited.insert(start);
	while (q.size()) {
		int levelSize = q.size();
		for (int i = 0;i < levelSize;++i) {
			int curr = q.front();
			q.pop();
			std::cout << curr << ' ';
			for (auto& v : graph[curr]) {
				if (!visited.count(v)) {
					q.push(v);
					visited.insert(v);
				}
			}
		}
	}
}

void dfs(int start, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
	visited.insert(start);
	cout << start << ' ';
	for (auto& v : graph[start]) {
		if (!visited.count(v)) {
			dfs(v, graph, visited);
		}
	}
}

int main() {
	return 0;
}
