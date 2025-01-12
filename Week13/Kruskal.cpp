/*
Kruskal algorithm for MST
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, cost;
    bool operator<(const Edge& other) {
        return cost < other.cost;
    }
};

int find(vector<int>& root, int x) {
    return root[x] == x ? x : root[x] = find(root, root[x]);
}

bool unite(vector<int>& root, int x, int y) {
    int parentX = find(root, x);
    int parentY = find(root, y);
    if (parentX == parentY)return false;
    root[parentX] = parentY;
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> root(N + 1);
    for (int i = 0;i <= N;i++) {
        root[i] = i;
    }
    int from, to, cost;
    vector<Edge> edges;
    for (int i = 0;i < M;i++) {
        cin >> from >> to >> cost;
        edges.push_back({ from, to, cost });
    }
    std::sort(edges.begin(), edges.end());
    int counter = 0;
    vector<Edge> result;
    for (auto it : edges) {
        if (unite(root, it.from, it.to)) {
            counter++;
            result.push_back(it);
        }
        if (counter == N - 1) {
            break;
        }
    }

    if (result.size() < N - 1) {
        cout << "Graph is not connected!";
        return -1;
    }

    for (int i = 0;i < result.size();i++) {
        std::cout << result[i].from << " -> " << result[i].to << " at cost: " << result[i].cost<<endl;
    }
}
