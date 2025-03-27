/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Leetcode 22
*/

class Solution {
public:

    char open = '(';
    char close = ')';

    void generate(vector<string>& result, int n, int opened, int closed, string&& current){
        if(current.size() == n*2){
            result.push_back(current);
            return;
        }
        if(opened < n){
            generate(result, n, opened+1, closed, current + open);
        }
        if(closed < opened){
            generate(result, n, opened, closed+1, current + close);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, n, 0, 0, "");
        return result;
    }
};
