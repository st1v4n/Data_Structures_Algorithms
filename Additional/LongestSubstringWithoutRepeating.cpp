/*
Given a string s, find the length of the longest substring without duplicate characters.
Leetcode 3
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int total = 0;
        unordered_set<char> uset;
        for(int i=0;i<s.size();++i){
            if(!uset.count(s[i])){
                uset.insert(s[i]);
                total = max(total, i-left+1);
            }
            else{
                while(uset.count(s[i])){
                    uset.erase(s[left]);
                    left++;
                }
                uset.insert(s[i]);
            }
        }
        return total;   
    }
};
