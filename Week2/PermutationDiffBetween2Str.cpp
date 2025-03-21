/*
You are given two strings s and t such that every character occurs at most once in s and t is a permutation of s.

The permutation difference between s and t is defined as the sum of the absolute difference between the index of the occurrence of each character in s and the index of the occurrence of the same character in t.

Return the permutation difference between s and t.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int indexes[26]{ 0 };
        for (int i = 0;i < t.size();i++) {
            indexes[t[i] - 'a'] = i;
        }
        int count = 0;
        for (int i = 0;i < s.size();i++) {
            count += abs(i - indexes[s[i] - 'a']);
        }
        return count;
    }
};