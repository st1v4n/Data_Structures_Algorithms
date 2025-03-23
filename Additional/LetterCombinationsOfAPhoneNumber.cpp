/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Leetcode 17
*/

class Solution {
public:

    unordered_map<char, string> alphabet;

    void solve(vector<string>& result, string current, string& digits, int index){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<alphabet[digits[index]].size();++i){
            solve(result, current + alphabet[digits[index]][i], digits, index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";
        vector<string> result;
        string current = "";
        solve(result, current, digits, 0);
        return result;
    }
};
