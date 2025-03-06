/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
Leetcode 2965
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> counts(n*n + 1,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                counts[grid[i][j]]++;
            }
        }
        int appTwice = 1;
        int appZero = 1;
        for(int i=1;i<counts.size();++i){
            if(counts[i]==2)appTwice=i;
            if(counts[i]==0)appZero=i;
        }
        return {appTwice, appZero};
    }
};
