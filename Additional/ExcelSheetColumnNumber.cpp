/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
Leetcode 171
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = 0;
        for(int i=0;i<columnTitle.size();++i){
            total = total*26 + (columnTitle[i] - 'A') + 1; 
        }
        return total;
    }
};
