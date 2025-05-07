/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Leetcode 438
*/

class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())return {};
        unordered_map<char, int> countsP;
        for(char sym:p){
            countsP[sym]++;
        }
        unordered_map<char, int> countsS;
        vector<int> result;
        int count = p.size();
        int end = s.size() - count;
        bool flag = false;
        for(int i=0;i<count;++i){
            countsS[s[i]]++;
        }
        for(int i=0;i<=end;++i){
            for(auto& it:countsP){
                if(it.second != countsS[it.first]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                result.push_back(i);
            }
            flag = false;
            countsS[s[i]]--;
            countsS[s[i + count]]++;
        }
        return result;
    }
};
