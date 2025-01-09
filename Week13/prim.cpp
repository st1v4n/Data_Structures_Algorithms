#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct Edge {
    int from, to, cost;
    bool operator>(const Edge& other) {
        return this->cost > other.cost;
    }
};

vector<Edge> prim(int n, int start, unordered_map<int, vector<Edge>>& graph) {
    priority_queue<Edge, vector<Edge>, std::greater<>> pq;
    unordered_set<int> visited;
    pq.push({ start, start, 0 });
    std::vector<Edge> mst;
    while (pq.size() && visited.size() < n) {
        auto curr = pq.top();
        pq.pop();
        if (visited.count(curr.to)) {
            continue;
        }
        mst.push_back(curr);
        visited.insert(curr.to);
        for (auto& edge : graph[curr.to]) {
            if (visited.count(edge.to)) {
                continue;
            }
            pq.push(edge);
        }
    }
    return mst;
}

int main() {
    
}
