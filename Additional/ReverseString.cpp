/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
Leetcode 344
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            std::swap(s[left++], s[right--]);
        }
    }
};
