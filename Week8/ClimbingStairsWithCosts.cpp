class Solution {
    int costs[1001]{0};
public:
    int minCostClimbingStairs(vector<int>& cost) {
        costs[0] = cost[0];
        costs[1] = cost[1];
        for(int i=2;i<cost.size();i++){
            costs[i] = min(costs[i-1],costs[i-2]) + cost[i];
        }
        return min(costs[cost.size()-1], costs[cost.size()-2]);
    }
};

