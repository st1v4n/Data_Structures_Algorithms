/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
Leetcode 168
*/

class Solution {

    public String convertToTitle(int columnNumber) {
        StringBuilder s = new StringBuilder();
        while(columnNumber > 0){
            columnNumber--;
            s.append((char)((columnNumber%26) + 'A'));
            columnNumber/=26;
        }
        return s.reverse().toString();
    }
}
