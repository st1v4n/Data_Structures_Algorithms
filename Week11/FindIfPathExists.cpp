/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

class Solution {
public:
    

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(int i =0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(source);
        visited[source] = true;
        while(q.size()){
            int curr = q.front();
            q.pop();
            if(curr==destination)return true;
            for (auto &v : g[curr]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] =true;
                }
            }
        }
        return false;
    }
};
