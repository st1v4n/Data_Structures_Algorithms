/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.
*/

class Solution {
public:
    
    void dfs(vector<int>& visited, int& curr, vector<vector<int>>& g, int& vCurr, int& eCurr){
        visited[curr] = true;
        vCurr++;
        eCurr += g[curr].size();
        for (auto &v: g[curr]){
            if(!visited[v]){
                dfs(visited, v, g, vCurr, eCurr);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(int i=0; i<edges.size(); ++i){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int counter = 0;
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++){
            int vCurr = 0;
            int eCurr = 0;
            if(!visited[i]){
                dfs(visited, i, g, vCurr, eCurr);
                if(vCurr*(vCurr-1)==eCurr){
                    counter++;
                }
            }
        }
        return counter;
    }
};
