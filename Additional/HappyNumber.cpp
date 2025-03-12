/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
Leetcode 202
*/

class Solution {
public:

    int calculateNumber(int number){
        int result = 0;
        while(number){
            int lastDigit = number%10;
            number/=10;
            result += lastDigit*lastDigit;
        }
        return result;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;
        while(true){
            if(n==1)return true;
            n=calculateNumber(n);
            if(visited.count(n))return false;
            visited.insert(n);
        }
        return false;
    }
};
