/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       vector<pair<int, int>> data;
for (int i = 0;i < nums.size();i++) {
    pair<int,int> help(nums[i], i);
    data.push_back(help);
}
std::sort(data.begin(), data.end());
for (int i = 1;i < data.size();i++) {
    if (data[i].first == data[i - 1].first && abs(data[i].second - data[i - 1].second) <= k) {
        return true;
    }
}
return false;
    }
};
