/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* iter = nullptr;
        priority_queue<int, vector<int>, std::greater<>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* curr = lists[i];
            while(curr){
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        if(pq.size()){
            iter = new ListNode(pq.top());
            pq.pop();
        }
        ListNode* head = iter;
        while(pq.size()){
            iter->next = new ListNode(pq.top());
            pq.pop();
            iter = iter->next;
        }
        return head;
    }
};
