/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
Leetcode 190
*/

class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t total = UINT32_MAX;
        uint32_t mult = (1<<31);
        int cycleCount = 32;
        while(cycleCount--){
            total -= n%2==0 ? mult : 0;
            n>>=1;
            mult /= 2;
        }
        return total;
    }
};
