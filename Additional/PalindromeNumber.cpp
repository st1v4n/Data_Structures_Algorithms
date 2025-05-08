/*
Given an integer x, return true if x is a palindrome, and false otherwise.
Leetcode 9
*/

class Solution {
public:

    int64_t reverse(int x){
        int64_t result = 0;
        while(x){
            (result*=10)+=x%10;
            x /=10;
        }
        return result;
    }

    bool isPalindrome(int x) {
        if(x<0)return false;
        return (int64_t)x == reverse(x);
    }
};
