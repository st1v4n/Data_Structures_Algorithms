/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Leetcode 7
*/

class Solution {
public:

    int countDigits(int x){
        if(x==0)return 1;
        int count = 0;
        while(x){
            x/=10;
            count++;
        }
        return count;
    }

    int powerOfTen(int power){
        int result = 1;
        for(int i=1;i<=power;++i){
            result*=10;
        }
        return result;
    }

    int reverse(int x) {
        int mult = x<0 ? -1 : 1;
        int count_digits = countDigits(x);
        if(count_digits > 9 && (x%10 >2 || x%10 < -2))return 0;
        int addition = (powerOfTen(count_digits-1))*mult;
        int64_t result = 0;
        while(x){
            int lastDigit = abs(x%10);
            result += lastDigit*addition;
            addition/=10;
            x/=10;
        }
        if(result < 0){
            return result > INT32_MIN ? result : 0;
        }
        else{
            return result < INT32_MAX ? result : 0;
        }
    }
};
