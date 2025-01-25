/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
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

    int get_size(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        if(!head){
            return {};
        }
        int sz = get_size(head);
        stack<int> monoton;
        stack<int> indexes;
        vector<int> result(sz);
        int iter = 0;
        while(head){
            while(monoton.size() && monoton.top() < head->val){
                monoton.pop();
                result[indexes.top()] = head->val;
                indexes.pop();
            }
            monoton.push(head->val);
            indexes.push(iter);
            iter++;
            head = head->next;
        }
        return result;
    }
};
