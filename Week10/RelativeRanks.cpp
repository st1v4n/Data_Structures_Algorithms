/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> h(score.size());
        for(int i=0;i<h.size();i++){
            h[i] = {score[i], i};
        }
        vector<string> res(h.size());
        std::priority_queue<pair<int,int>> pq(h.begin(), h.end());
        if(pq.size()){
            int idx = pq.top().second;
            res[idx] = "Gold Medal";
            pq.pop();
        }
        if(pq.size()){
int idx = pq.top().second;
            res[idx] = "Silver Medal";
            pq.pop();
        }
        if(pq.size()){
int idx = pq.top().second;
            res[idx] = "Bronze Medal";
            pq.pop();
        }
        int iter = 4;
        while(pq.size()){
            int idx = pq.top().second;
            res[idx] = std::to_string(iter++);
            pq.pop();
        }
        return res;
    }
};
