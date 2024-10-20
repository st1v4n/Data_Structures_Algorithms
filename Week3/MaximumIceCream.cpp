/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int data[100001]{ 0 };
        int count = 0;
        int max = costs[0];
        for (int i = 1;i < costs.size();i++) {
            if (costs[i] > max) {
                max = costs[i];
            }
        }
        for (int i = 0;i < costs.size();i++) {
            data[costs[i]]++;
        }
        for (int i = 0;i <= max;i++) {
            for (int j = 0;j < data[i];j++) {
                if (coins >= i) {
                    coins -= i;
                    count++;
                }
                if (coins <= 0)return count;
            }
        }
        return count;
    }
};
