/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
Leetcode 160
*/

//First Solution: using two addition pointers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first = headA;
        ListNode* second = headB;
        while(first != second){
            if(first == nullptr){
                first = headB;
            }
            else{
                first=first->next;
            }
            if(second==nullptr){
                second=headA;
            }
            else{
                second=second->next;
            }
        }
        return first;
    }
};

//Second Solution: using unordered_set

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> uset;
        while(headA){
            uset.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(uset.count(headB))return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
