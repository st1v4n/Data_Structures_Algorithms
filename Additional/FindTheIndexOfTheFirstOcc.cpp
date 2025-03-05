/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Leetcode 28
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();++i){
            if(haystack[i]==needle[0]){
                for(int j=1;j<needle.size();++j){
                    if(needle[j]!=haystack[i+j])break;
                    if(j==needle.size()-1)return i;
                }
                if(needle.size()==1)return i;
            }
        }
        return -1;
    }
};
