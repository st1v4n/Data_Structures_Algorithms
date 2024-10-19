/*
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int, int>> help;
        for (int i = 0;i < groupSizes.size();i++) {
            pair<int, int> p(groupSizes[i], i);
            help.push_back(p);
        }
        std::sort(help.begin(), help.end());
        vector<vector<int>> result;
        int iter = 0;
        for (int i = 0;i < help.size();i++) {
            int curr_index = i;
            for (int j = 0;j < help[curr_index].first;j++) {
                if (j == 0) {
                    vector<int> temp;
                    result.push_back(temp);
                }
                result[iter].push_back(help[i++].second);
            }
            --i;
            iter++;
        }
        return result;
    }
};