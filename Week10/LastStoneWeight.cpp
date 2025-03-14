/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

class Solution {
public:
    int first, second;

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();++i){
            pq.push(stones[i]);
        }
        while(pq.size()){
           first = pq.top();
           pq.pop();
           if(pq.size()<1){
            return first;
           }
           second = pq.top();
           pq.pop();
           if(first != second){
            pq.push(first-second);
           }
        }
        return pq.size() == 0 ? 0 : pq.top();
    }
};
