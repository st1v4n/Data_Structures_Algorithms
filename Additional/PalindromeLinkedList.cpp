/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Leetcode 234
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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* copy = head;
        while(copy){
            st.push(copy->val);
            copy=copy->next;
        }
        while(head){
            if(head->val != st.top())return false;
            head=head->next;
            st.pop();
        }
        return head==nullptr;
    }
};
