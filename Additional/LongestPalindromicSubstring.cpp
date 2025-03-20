/*
Given a string s, return the longest palindromic substring in s.
Leetcode 5
*/

// Solution 1: using Dynamic programming
class Solution {
public:

    string longestPalindrome(string& s) {
        if(s.size()==1)return s;
        int curr_max = 1;
        int left = 0;
        int right = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),0));
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
            for(int j=0;j<i;++j){
                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    int diff = i-j+1;
                    if(diff>curr_max){
                        curr_max=diff;
                        left = j;
                        right = i;
                    }
                }
            }
        }
        return s.substr(left, right-left+1);
    }
};

// Solution 2: What came to my mind at first (brute force)

class Solution {
public:

    bool isPalindrome(const string& s, int start, int end){
        while(start < end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string& s) {
        int result = 1;
        int n = s.size();
        int left = 0;
        int right = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;j++){
                if(isPalindrome(s, i, j)){
                    int diff = j-i+1;
                    if(diff > result){
                        result = diff;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return s.substr(left, right-left+1);
    }
};
