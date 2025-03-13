/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Leetcode 242
*/

class Solution {
public:

    int arr[128]{0};

    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();++i){
            arr[s[i]]++;
        }
        for(int i=0;i<t.size();++i){
            if(arr[t[i]]){
                arr[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
