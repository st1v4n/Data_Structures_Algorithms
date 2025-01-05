/*
you are given V,E,s,e - number of stops, number of connections between two stops, startPoint, endPoint
each stop has an interval of time, at which the bus arrives at that stop
find the shortest time it requires to travel between the startPoint and endPoint
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int max_size = 1e4 + 1;
int intervals[max_size];
unordered_map<int, int> graph[max_size];
int V, E, s, e;

int dijkstra(int start, int end) {
    vector<int> distances(V, INT32_MAX);
    distances[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
    pq.push({ 0, start });
    while (pq.size()) {
        auto curr = pq.top();
        pq.pop();
        if (curr.first > distances[curr.second]) {
            continue;
        }
        if (curr.second == end) {
            return distances[end];
        }
        for (auto& edge : graph[curr.second]) {
            int cost = curr.first + edge.second;
            int wait = curr.first % intervals[curr.second];
            if (wait != 0) {
                cost += intervals[curr.second] - wait;
            }
            if (cost < distances[edge.first]) {
                distances[edge.first] = cost;
                pq.push({ cost, edge.first });
            }
        }
    }
    return -1;
}

int main() {
    cin >> V >> E >> s >> e;
    for (int i = 0;i < V;++i) {
        cin >> intervals[i];
    }
    int a, b, c;
    for (int i = 0;i < E;++i) {
        cin>>a>>b>>c;
        if(!graph[a].count(b)){
            graph[a].insert({b, c});
        }
        else{
            if(graph[a][b] > c){
                graph[a][b] = c;
            }
        }
    }
    cout << dijkstra(s, e);
    return 0;
}
