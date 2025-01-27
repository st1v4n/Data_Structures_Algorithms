/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/

class Solution {
public:

    vector<vector<int>> result;
    void dfs(int curr, vector<vector<int>>& graph, vector<int>& currentPath){
        currentPath.push_back(curr);
        if(curr == graph.size()-1){
            result.push_back(currentPath);
        }
        for(auto& v:graph[curr]){
            dfs(v, graph, currentPath);
        }
        currentPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currentPath;
        dfs(0, graph, currentPath);
        return result;
    }
};
