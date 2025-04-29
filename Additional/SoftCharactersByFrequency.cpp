/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
Leetcode 451
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        priority_queue<pair<int, char>> pq;
        int i;
        for(i=0;i<s.size();++i){
            umap[s[i]]++;
        }
        for(auto& element:umap){
            pq.push({element.second, element.first});
        }
        string result;
        while(pq.size()){
            char current = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            for(i=0;i<freq;++i){
                result.push_back(current);
            }
        }
        return result;
    }
};
