/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

class Solution {
public:
    int cache[31]{0};
    int fibbonacci(int n){
        if(n<=1){
            return n;
        }
        if(!cache[n]){
            cache[n] = fibbonacci(n-1) + fibbonacci(n-2);
        }
        return cache[n];
    }

    int fib(int n) {
        return fibbonacci(n);
    }
};
