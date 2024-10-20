/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter1 = m - 1;
        int iter2 = n - 1;
        for (int counter = n + m - 1;counter >= 0; counter--) {
            if (iter1 < 0) {
                while (iter2 >= 0) {
                    nums1[counter--] = nums2[iter2--];
                }
                break;
            }
            if (iter2 < 0) {
                while (iter1 >= 0) {
                    nums1[counter--] = nums1[iter1--];
                }
                break;
            }
            if (nums1[iter1] < nums2[iter2]) {
                nums1[counter] = nums2[iter2--];
            }
            else {
                nums1[counter] = nums1[iter1--];
            }
        }
    }
};