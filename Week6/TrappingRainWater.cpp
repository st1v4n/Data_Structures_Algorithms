/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <deque>

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::deque<std::pair<int, int>> blocks;
        int trappedWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (blocks.size() && blocks.back().first < height[i]) { 
                auto block = blocks.back(); 
                blocks.pop_back();          
                if (blocks.empty()) {       
                    continue;
                }

                int waterBlocks = std::min(height[i], blocks.front().first) - block.first;
                int interval = block.second - blocks.back().second;
                trappedWater += waterBlocks * interval;
            }

            blocks.push_back({ height[i], i });
        }

        return trappedWater;
    }
};