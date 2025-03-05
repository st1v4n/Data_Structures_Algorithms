/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
Leetcode 14
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int iterRight = strs[0].size();
        for(int i=1;i<strs.size();++i){
            int currSize = std::min(strs[i].size(), strs[0].size());
            if(currSize < iterRight){
                iterRight = currSize;
            }
            for(int j=0;j<currSize;++j){
                if(strs[i][j]!=strs[0][j]){
                    iterRight = std::min(j, iterRight);
                }
            }
        }
        string result = strs[0].substr(0, iterRight);
        return result;
    }
};
