/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Leetcode 119
*/

class Solution {
    public List<Integer> getRow(int rowIndex) {
        if(rowIndex == 0){
            List<Integer> r = new ArrayList<>();
            r.add(1);
            return r;
        }
        else if(rowIndex == 1){
            List<Integer> r = new ArrayList<>();
            r.add(1);
            r.add(1);
            return r;
        }
        int arr[] = new int[2];
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2;i<=rowIndex; ++i){
            int curr[] = new int[i+1];
            curr[i] = 1;
            curr[0] = 1;
            for(int j = 1;j<i;j++){
                curr[j] = arr[j-1] + arr[j];
            }
            arr = curr;
        }
        List<Integer> result = new ArrayList<>();
        for(int i = 0;i<arr.length;++i){
            result.add(arr[i]);
        }
        return result;
    }
}
