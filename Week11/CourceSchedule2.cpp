/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

class Solution {
public:
    
    stack<int> topological;

    bool dfs(int& curr, vector<vector<int>>& g, vector<int>& color){
        color[curr] = 1;

        for(auto &v : g[curr]){
            if(color[v] == 1){
                return true;
            }
            if(color[v] == 2){
                continue;
            }
            if(dfs(v, g, color)){
                return true;
            }
        }
        color[curr] = 2;
        topological.push(curr);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> color(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!color[i]){
                if(dfs(i, g, color)){
                    return {};
                }
            }
        }
        vector<int> result;
        while(topological.size()){
            result.push_back(topological.top());
            topological.pop();
        }
        return result;
    }
};
