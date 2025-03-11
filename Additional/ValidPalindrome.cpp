/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Leetcode 125
*/

class Solution {
public:

    bool isValid(char sym){
        return (sym>='a' && sym<='z') || (sym>='A' && sym<='Z') || (sym>='0' && sym<='9');
    }

    bool isUpper(char sym){
        return sym >= 'A' && sym <= 'Z';
    }

    bool equals(char first, char second){
        if(first == second)return true;
        if(isUpper(first))first += 'a' - 'A';
        if(isUpper(second))second += 'a' - 'A';
        return first == second;
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            while(left < s.size()-1 && !isValid(s[left])){
                left++;
            }
            while(right > 0 && !isValid(s[right])){
                right--;
            }
            if(left > right)break;
            if(equals(s[left], s[right])){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
