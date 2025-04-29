/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Leetcode 347
*/

struct Element{
    int frequency;
    int value;
    bool operator>(const Element& other) const{
        return frequency < other.frequency;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<Element, vector<Element>, std::greater<>> pq;
        unordered_map<int, int> umap;
        for(int i=0;i<nums.size();++i){
            umap[nums[i]]++;
        }
        for(auto& number: umap){
            pq.push({number.second, number.first});
        }
        vector<int> result(k);
        for(int i=0;i<k;++i){
            result[i] = pq.top().value;
            pq.pop();
        }
        return result;
    }
};
