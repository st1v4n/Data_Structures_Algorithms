/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Leetcode 1584
*/

class Solution {
public:

    struct Edge{
        int from, to, cost;
        bool operator>(const Edge& other){
            return this->cost > other.cost;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<Edge, vector<Edge>, std::greater<>> pq;
        unordered_set<int> visited;
        visited.insert(0);
        int total = 0;
        for(int i=1;i<points.size();i++){
            int distance = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            pq.push({0, i, distance});
        }
        while(pq.size() && visited.size() < points.size()){
            auto curr = pq.top();
            pq.pop();
            if(visited.count(curr.to)){
                continue;
            }
            visited.insert(curr.to);
            total += curr.cost;
            for(int i = 1; i < points.size(); i++){
                if(visited.count(i)){
                    continue;
                }
                int distance = abs(points[curr.to][0] - points[i][0]) + abs(points[curr.to][1] - points[i][1]);
                pq.push({curr.to, i, distance});
            }
        }
        return total;
    }
};
