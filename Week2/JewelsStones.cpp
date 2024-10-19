/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        constexpr int size = 128;
        bool jewel_app[size]{ false };
        for (int i = 0;i < jewels.size();i++) {
            jewel_app[jewels[i]] = true;
        }
        int count = 0;
        for (int i = 0;i < stones.size();i++) {
            if (jewel_app[stones[i]] == true) {
                count++;
            }
        }
        return count;
    }
};