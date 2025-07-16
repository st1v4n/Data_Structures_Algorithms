/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
Leetcode 228
*/

class Solution {
    public List<String> summaryRanges(int[] nums) {
        if(nums.length == 0)return new ArrayList<String>();
        StringBuilder current = new StringBuilder();
        Integer previous = nums[0];
        List<String> result = new ArrayList<>();
        int counter = 1;
        for(int i = 1; i < nums.length; ++i){
            if(previous + counter != nums[i]){
                if(counter == 1){
                    result.add(previous.toString());
                    previous = nums[i];
                    continue;
                }
                else{
                    result.add(previous.toString() + "->" + String.valueOf(nums[i-1]));
                    previous = nums[i];
                    counter = 1;
                    continue;
                }
            }
            counter++;
        }
        if(previous == nums[nums.length - 1]){
            result.add(previous.toString());
        }
        else{
            result.add(previous.toString() + "->" + String.valueOf(nums[nums.length-1]));
        }
        return result;
    }
}
