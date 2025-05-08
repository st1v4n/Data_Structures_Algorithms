/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
Leetcode 58
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool wordDetected = false;
        for(int i = s.size()-1;i>-1;--i){
            if(s[i] == ' ' && wordDetected)return count;
            if(s[i] != ' '){
                wordDetected = true;
            }
            if(wordDetected)count++;
        }
        return count;
    }
};
