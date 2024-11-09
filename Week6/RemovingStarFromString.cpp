/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i = 0; i < s.length();i++) {
            if (s[i] != '*') {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }
        string res(st.size(), '\0');
        for (int i = st.size() - 1;i > -1;i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
