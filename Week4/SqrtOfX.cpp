/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int result = x;
        while(left <= right){
            uint64_t mid = left + (right - left) / 2;
            uint64_t power = mid * mid;
            if(power > x){
                right = mid - 1;
            }
            else if(power == x){
                return mid;
            }
            else{
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }
};
