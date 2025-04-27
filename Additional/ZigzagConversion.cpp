/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Leetcode 6
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int y=0;
        bool isDiagonal = false;
        vector<vector<char>> table(numRows);
        for(int i=0;i<s.size();++i){
            table[y].push_back(s[i]);
            if(y+1 == numRows){
                isDiagonal = true;
            }
            if(isDiagonal){
                y--;
            }
            else{
                y++;
            }
            if(y==0){
                isDiagonal = false;
            }
        }
        string result;
        for(int i=0; i<numRows; ++i){
            for(int j =0; j<table[i].size(); ++j){
                result.push_back(table[i][j]);
            }
        }
        return result;
    }
};
