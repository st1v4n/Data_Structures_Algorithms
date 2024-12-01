/*
You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.
*/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        std::vector<int> help;
        vector<int> res(queries.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                help.push_back(i);
            }
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i]>help.size()){
                res[i] = -1;
            }
            else{
                res[i] = help[queries[i]-1];
            }
        }
        return res;
    }
};
