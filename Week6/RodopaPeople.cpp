/*
Enter N and K
In the next N rows, enter a number 
Print The minimal number in each group of K elements in N

example:
5 2
1 2 3 4 5
first we get [1 2] 3 4  5
1 [2 3] 4 5
1 2 [3 4] 5
...
and we find the minimal in each group
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> p(N);
    deque<int64_t> d;
    for (int i = 0;i < N;i++) {
        cin >> p[i];
    }

    for (int i = 0;i < K;i++) {
        while (d.size() && d.back() > p[i]) {
            d.pop_back();
        }
        d.push_back(p[i]);
    }
    int64_t sum = d.front();
    for (int i = K;i < N;i++) {
        if (d.front() == p[i - K])d.pop_front();
        while (d.size() && d.back() > p[i]) {
            d.pop_back();
        }
        d.push_back(p[i]);
        sum += d.front();
    }
    cout << sum;
    return 0;
}