/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<succProb.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> distances(n, 0.0);
        distances[start] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while(pq.size()){
            auto curr = pq.top();
            pq.pop();
            if(curr.second == end){
                return distances[end];
            }
            if(curr.first < distances[curr.second]){
                continue;
            }
            for(auto &edge:graph[curr.second]){
                double cost = curr.first * edge.second;
                if(distances[edge.first] < cost){
                    distances[edge.first] = cost;
                    pq.push({cost, edge.first});
                }
            }
        }
        return 0.0;
    }
};
