/*
You are given Q: number of queries
On the next Q rows, you are given N and C: number of Groups AND capacity of the Bus
    On the Next N rows, you are given K, X, Y: number of people in a group AND when they catch the bus AND when they leave the bus
Return for each query if it possible to fit all the passagers into the bus
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Group{
    int size, join, leave;
    
    friend bool operator<(const Group& curr, const Group& other){
        return curr.join < other.join;
    }
};

bool isPossible(vector<Group>& groups, int& N, int& C){
    std::sort(groups.begin(), groups.end());
    std::priority_queue<pair<int, int>, vector<pair<int,int>>, std::greater<>> pq;
    if(!groups.size()){
        return true;
    }
    int iter = 0;
    while(true){
        if(iter == groups.size())break;
        while(pq.size() && pq.top().first <= groups[iter].join){
            C+= pq.top().second;
            pq.pop();
        }
        pq.push({groups[iter].leave, groups[iter].size});
        C-=groups[iter].size;
        if(C<0)return false;
        iter++;
    }
    return true;
}

int main() {
    int Q, N, C;
    cin>>Q;
    vector<bool> queries(Q);
    for(int i=0;i<Q;i++){
        cin>>N>>C;
        vector<Group> groups(N);
        for(int j=0;j<N;j++){
            cin>>groups[j].size;
            cin>>groups[j].join;
            cin>>groups[j].leave;
        }
        queries[i] = isPossible(groups, N, C);
    }
    for(int i=0;i<Q;i++){
        std::cout<<queries[i]<<endl;
    }
    return 0;
}
