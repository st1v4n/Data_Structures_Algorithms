/*
We enter a Number N
On the next N rows we enter a number

each negative number represents a movevent to the left, while positive numbers represent a movement to the right

Example:

4

5 -6 3 -2

the 5 moves to the right
then meets up with the -6
because abs(-6) is > 5, the 5 gets destroyed
if they were equal, they would both get destroyed

at the end, those who wont be destroyed will be -6 and 3

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> p(N);
    for (int i = 0;i < N;i++) {
        cin >> p[i];
    }
    stack<int64_t> s;
    for (int i = 0; i < N; i++) {
        if (!s.size())s.push(p[i]);
        else if (p[i] < 0) {
            int64_t abs_i = abs(p[i]);
            while (s.size() && s.top() > 0 && abs_i > s.top()) {
                s.pop();
            }
            if (s.size() && abs_i == s.top()) {
                s.pop();
                continue;
            }
            if (!s.size() || s.top() < 0) {
                s.push(p[i]);
            }
        }
        else {
            s.push(p[i]);
        }
    }
    vector<int64_t> res(s.size());
    for (int i = s.size() - 1;i > -1;i--) {
        res[i] = s.top();
        s.pop();
    }
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << ' ';
    }
    return 0;
}