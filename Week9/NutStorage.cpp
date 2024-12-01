/*
You are given T - number of queries
On the Next T rows, you are given:
X - number of wanted kilograms
N- number of cartons in the storage
W[i] - mass of a carton

return the indexes of the 2 cartons (for each different query), where their sums add up to X (w[i] + w[j] = X, if the indexes are i and j)
*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int T;
    cin>>T;
    uint64_t X;
    int N;
    for(int i=0;i<T;i++){
        cin>>X;
        cin>>N;
        unordered_map<uint64_t,int> umap;
        for(int j=0;j<N;j++){
            uint64_t w;
            cin>>w;
            if(umap.count(X-w)){
                cout<<umap[X-w] + 1<<' '<<j + 1<<endl;
            }
            umap.insert({w,j});
        }
    }
    
    return 0;
}
