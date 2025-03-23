/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Leetcode 19
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int sz = 0;
        ListNode* iter = head;
        while(iter){
            sz++;
            iter=iter->next;
        }
        int stop = sz-n+1;
        int count = 1;
        while(curr){
            if(count == stop){
                if(prev){
                    prev->next = curr->next;
                    break;
                }
                else{
                    head = head->next;
                }
            }
            prev = curr;
            curr=curr->next;
            count++;
        }
        return head;
    }
};
