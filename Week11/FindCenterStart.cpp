/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> g;
        pair<int,int> curr({edges[0][0], edges[0][1]});
        for(int i=1;i<edges.size();i++){
            if(edges[i][0] == curr.first || edges[i][0] == curr.second){
                return edges[i][0];
            }
            else if(edges[i][1] == curr.first || edges[i][1] == curr.second){
                return edges[i][1];
            }
        }
        
        return -1;
    }
};
