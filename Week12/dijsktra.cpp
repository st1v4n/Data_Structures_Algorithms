// dijsktra algorithm for finding shortest path in a graph (where every edge is with cost >= 0)

struct Edge {
	int to, cost;
};

struct Node{
	int index, distance;
};

std::vector<int> dijkstra(int start, int N, unordered_map<int, vector<Edge>>& graph) {
	vector<int> distances(N, INT_MAX);
	distances[start] = 0;
	priority_queue<Node> pq;
	pq.push({ start, 0 });
	while (pq.size()) {
		Node current = pq.top();
		pq.pop();
		if (current.distance > distances[current.index]) {
			continue;
		}
		for (auto& edge : graph[current.index]) {
			int cost = current.distance + edge.cost;
			if (cost < distances[edge.to]) {
				distances[edge.to] = cost;
				pq.push({ edge.to, cost });
			}
		}
	}
	return distances;
}
