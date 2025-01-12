/*
you are given n: number of vertexes
you are give m: number of edges
s and t: start and end points
v1, v2, w: edge from v1 to v2 with  cost w
print the longest path connecting s and t
if such doesnt exist, print -1
*/

#include <bits/stdc++.h>
using namespace std;

int n,m,s,t,v1,v2,w;

struct Edge{
  int from, to;
  int64_t cost;
};

int main() {
    cin>>n>>m>>s>>t;
    vector<Edge> edges;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>w;
        edges.push_back({v1,v2,w});
    }
    vector<int64_t> distances(n+1, INT64_MIN);
    distances[s] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            distances[edges[j].to] = std::max(distances[edges[j].to], distances[edges[j].from] + edges[j].cost);
        }
    }
    if(distances[t] == INT64_MIN){
        cout<<-1;
        return 0;
    }
    cout<<distances[t];
    return 0;
}
