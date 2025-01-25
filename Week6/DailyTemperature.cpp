/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monoton;
        vector<int> result(temperatures.size());
        for(int i=0;i<temperatures.size();++i){
            while(monoton.size() && temperatures[monoton.top()] < temperatures[i]){
                result[monoton.top()] = i-monoton.top();
                monoton.pop();
            }
            monoton.push(i);
        }
        return result;
    }
};
