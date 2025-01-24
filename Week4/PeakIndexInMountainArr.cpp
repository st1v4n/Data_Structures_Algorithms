/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};
