/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
Leetcode 264
*/

class Solution {
    int arr[3] = {2, 3, 5};
public:
    int nthUglyNumber(int n) {
        std::priority_queue<int64_t, vector<int64_t>, std::greater<>> pq;
        std::unordered_set<int64_t> visited;
        int64_t current;
        pq.push(1);
        visited.insert(1);
        for(int i=0;i<n;++i){
            current = pq.top();
            pq.pop();
            for(int j=0;j<3;++j){
                int64_t number = arr[j] * current;
                if(!visited.count(number)){
                    pq.push(number);
                    visited.insert(number);
                }
            }
        }
        return current;
    }
};
