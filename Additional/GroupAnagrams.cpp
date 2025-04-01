/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Leetcode 49
*/

class Solution {
public:

    string createString(vector<int> counts){
        string result;
        for(int i=0;i<26;++i){
            for(int c=0;c<counts[i];c++){
                result.push_back(i+'a');
            }
        }
        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(int i=0;i<strs.size();++i){
            vector<int> counts(26, 0);
            for(int j=0;j<strs[i].size();++j){
                counts[strs[i][j]-'a']++;
            }
            string current = createString(counts);
            umap[current].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto [key, value]:umap){
            result.push_back(value);
        }
        return result;
    }
};
