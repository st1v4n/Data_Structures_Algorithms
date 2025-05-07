/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
Leetcode 187
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int count = 10;
        int end = s.size() - count;
        unordered_map<string, int> umap;
        for(int i=0;i<=end;++i){
            string curr = s.substr(i, count);
            umap[curr]++;
        }
        vector<string> result;
        for(auto& it:umap){
            if(it.second > 1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
