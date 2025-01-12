/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:

    int root[201];

    int find(int x){
        return root[x] == x ? x : root[x] = find(root[x]); 
    }

    bool unite(int x, int y){
    int parentX = find(x);
    int parentY = find(y);
    if(parentX != parentY){
        root[parentX] = parentY;
        return true;
    }
    return false;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected[0].size();
       for(int i=0;i<n;i++){
        root[i] = i;
       }
       int counter = n;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    if(unite(i, j)){
                        counter--;
                    }
                    if(counter == 1){
                        break;
                    }
                }
           }
       }
       return counter;
    }
};
