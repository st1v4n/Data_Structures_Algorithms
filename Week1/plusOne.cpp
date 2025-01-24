/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size()-1;
        digits[size]++;
        while(size-1 >= 0 && digits[size] == 10){
            digits[size] = 0;
            digits[size-1]++;
            size--;
        }
        if(digits[0] == 10){
            vector<int> result(digits.size()+1);
            result[0] = 1;
            result[1] = 0;
            for(int i=1;i<digits.size();++i){
                result[i+1] = digits[i];
            }
            return result;
        }
        else{
            return digits;
        }
    }
};
