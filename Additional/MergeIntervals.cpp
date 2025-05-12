/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Leetcode 56
*/

auto comp = [] (const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    };

class Solution {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> result(1, intervals[0]);
        for(int i = 1;i<intervals.size();++i){
            vector<int>& back = result.back();
            if(back[1] >= intervals[i][0]){
                back[1] = std::max(intervals[i][1], back[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }  
        return result;
    }
};
