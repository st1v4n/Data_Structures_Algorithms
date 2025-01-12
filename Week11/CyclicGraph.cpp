/*
You are given N: number of qierues (different graphs)
You are given V and E
you are given x, y, w: from, to, cost
return for each query if there is a cycle in that graph
*/

#include <bits/stdc++.h>
using namespace std;

int N, V, E, x, y, w;

struct Edge{
    int to, cost;
};

unordered_map<int, unordered_set<int>> graph;

bool dfs(int index, unordered_map<int, unordered_set<int>>& graph, vector<int>& colors){
    colors[index] = 1;
    for(auto& edge:graph[index]){
        if(colors[edge] == 2)continue;
        if(colors[edge] == 1){
            return true;
        }
        if(dfs(edge, graph, colors))return true;
    }
    colors[index] = 2;
    return false;
}

bool checkForCycle(unordered_map<int, unordered_set<int>>& graph){
    vector<int> colors(V+1, 0);
    for(auto& v: graph){
        if(colors[v.first] != 0){
            continue;
        }
        if(dfs(v.first, graph, colors)){
            return true;
        }
    }
    return false;
}

int main() {
    cin>>N;
    vector<bool> results(N);
    for(int i=0;i<N;i++){
        cin>>V>>E;
        for(int i=1;i<=V;++i){
            graph[i];
        }
        for(int i=0;i<E;i++){
            cin>>x>>y>>w;
            graph[x].insert(y);
        }
        results[i] = checkForCycle(graph);
        graph.clear();
    }
    
    for(int i=0;i<N;i++){
        if(results[i]){
            cout<<"true"<<' ';
            continue;
        }
        cout<<"false"<<' ';
    }
    return 0;
}
