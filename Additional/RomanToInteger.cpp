/*
Convert a string from a roman number to integer (Leetcode 13)
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table;
        int result = 0;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        for(int i=0;i<s.size();++i){
            if(i+1<s.size() && table[s[i]]<table[s[i+1]]){
                result -= table[s[i]];
            }
            else{
                result += table[s[i]];
            }
        }
        return result;
    }
};
