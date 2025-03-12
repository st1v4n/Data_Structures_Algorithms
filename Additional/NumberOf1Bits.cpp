/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
Leetcode 191
*/

class Solution {
public:
    int hammingWeight(int n) {
        int total = 0;
        while(n){
            total += n%2==0 ? 0 : 1;
            n>>=1;
        }
        return total;
    }
};
