/*
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
Leetcode 1338
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int expectedSize = arr.size() / 2;
        unordered_map<int, int> umap;
        std::priority_queue<int> pq;
        for(int i=0;i<arr.size();++i){
            umap[arr[i]]++;
        }
        int currSize = arr.size();
        for(auto& element:umap){
            pq.push(element.second);
        }
        int count = 1;
        while(pq.size()){
            currSize -= pq.top();
            if(currSize <= expectedSize){
                return count;
            }
            count++;
            pq.pop();
        }
        return arr.size();
    }
};
