/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

class Solution {
public:

struct Edge{
    int to, cost;
};

struct Node{
    int dist, index;
    bool operator>(const Node& other){
        return dist > other.dist;
    }
};

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> graph(n+1);
        for(int i=0;i<times.size();++i){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> distances(n+1, INT32_MAX);
        priority_queue<Node, vector<Node>, std::greater<>> pq;
        distances[k] = 0;
        pq.push({0, k});
        while(pq.size()){
            auto curr = pq.top();
            pq.pop();
            if(curr.dist > distances[curr.index])continue;
            for(auto& edge: graph[curr.index]){
                int newCost = edge.cost + curr.dist;
                if(newCost < distances[edge.to]){
                    distances[edge.to] = newCost;
                    pq.push({newCost, edge.to});
                }
            }
        }
    int max = INT32_MIN;
    for(int i=1;i<=n;i++){
        if(max < distances[i])max=distances[i];
    }
    return max == INT32_MAX ? -1 : max;
    }
};
