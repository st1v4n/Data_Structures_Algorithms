/*
given N and M
on the next M rows you are given a number
generate the alphabetically lowest permutation of the N elements, where the M elements are in same order 
example:
5 //N
3 //M
1 4 2
output: 1 3 4 2 5
1 is before 4, 4 is before 2, and its the lowest of all permutations
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool counts[100001]{ 0 };

int main() {
    int N, M;
    cin >> N >> M;
    int a;
    cin >> a;
    int b;
    int key = a;
    unordered_map<int, int> umap;
    umap.insert({ a,0 });
    counts[a] = true;
    for (int i = 1;i < M;i++) {
        cin >> b;
        counts[b] = true;
        umap[a] = b;
        umap.insert({ b,0 });
        a = b;
    }
    for (int i = 1;i <= N;i++) {
        if (i == key) {
            while (umap[key] && key > umap[key]) {
                cout << key << ' ';
                key = umap[key];
            }
            while (key && key <= i) {
                cout << key << ' ';
                key = umap[key];
            }
        }
        else {
            if (!counts[i]) {
                cout << i << ' ';
            }
        }
    }
}



