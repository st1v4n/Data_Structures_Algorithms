/*
You are given N and M : number of crossroads (from 1 to N) and number of streets between them
Each street cleaning time is 1 hour
on the next M rows, you are given Ai and Bi : which 2 crossroads that street of index i connects
return the time when all crossroads are connected (when we have at least 1 path from every crossroad to other crossroads)
example:
6 8
1 2 // 1hour
4 5 // 2hour
2 5 // 3hour
3 1 // 4hour
3 5 // 5hour
6 5 // 6hour -> connected!
4 6
3 4
output:
6
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
int root[(int)1e5];

int find(int x){
    return root[x] == x ? x: root[x] = find(root[x]);
}

bool unite(int x, int y){
    int parentX = find(x);
    int parentY = find(y);
    if(parentX == parentY)return false;
    root[parentX] = parentY;
    return true;
}

int main() {
    cin>>N>>M;
    int count = 0;
    for(int i=1;i<=N;i++){
        root[i] = i;
    }
    if(N==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<M;++i){
        cin>>a>>b;
        if(unite(a, b)){
            ++count;
            
            if(count == N - 1){
            cout<<i+1;
            return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}
