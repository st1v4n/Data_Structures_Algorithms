/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Leetcode 2
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addition = 0;
        ListNode* result = new ListNode();
        ListNode* toReturn = result;
        while(l1 && l2){
            int toAdd = addition + l1->val + l2->val;
            result->val = (toAdd%10);
            if(toAdd/10)addition=1;
            else{
                addition=0;
            }
            if(l1->next || l2->next){
            result->next = new ListNode();
            result = result->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int toAdd = addition + l1->val;
            result->val = (toAdd%10);
            if(toAdd/10)addition=1;
            else{
                addition=0;
            }
            if(!l1->next)break;
            else{
                result->next = new ListNode();
                result = result->next;
            }
            l1=l1->next;
            
        }
        while(l2){
            int toAdd = addition + l2->val;
            result->val = (toAdd%10);
            if(toAdd/10)addition=1;
            else{
                addition=0;
            }
            if(!l2->next)break;
            else{
                result->next = new ListNode();
                result = result->next;
            }
            
            l2=l2->next;
        }
        if(addition == 1){
            result->next = new ListNode(1);
        }
        return toReturn;
    }
};
