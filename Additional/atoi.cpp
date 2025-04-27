/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
Leetcode 8
*/

class Solution {
public:

    int64_t charToInt(char ch){
        return ch - '0';
    }

    int myAtoi(string s) {
        int64_t result = 0;
        bool number = false;
        bool signedAlready = false;
        int mult = 1;
        for(int i=0;i<s.size();++i){
            if((s[i] == '+' || s[i] == '-' || s[i] == ' ') && signedAlready){
                return result*mult;
            }
            if(s[i] == ' ' && !number){
                continue;
            }
            if(s[i] == '-' && !number){
                signedAlready = true;
                mult = -1;
                continue;
            }
            if(s[i] == '+' && !number){
                signedAlready = true;
                continue;
            }
            if(s[i] == '0' && !number){
                number = true;
                continue;
            }
            if(s[i] > '0' && s[i] <= '9'){
                number = true;
                (result*=10)+=charToInt(s[i]);
                if(result > INT32_MAX){
                    return mult == 1 ? INT32_MAX : INT32_MIN;
                }
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9' && number){
                number = true;
                (result*=10)+=charToInt(s[i]);
                if(result > INT32_MAX){
                    return mult == 1 ? INT32_MAX : INT32_MIN;
                }
                continue;
            }
            if(((s[i] < '0' || s[i] > '9') && number) || (!number && s[i] != ' ')){
                break;
            }
        }
        return result*mult;
    }
};
