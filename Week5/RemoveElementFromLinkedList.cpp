/*
Remove Element From linked list where element = val
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)return nullptr;
        ListNode* start = head;
        ListNode* prev = head;
        start = head->next;
        while (prev && start && prev->val == val) {
            head = start;
            prev = prev->next;
            start = start->next;
        }
        while (start) {
            if (start->val == val) {
                prev->next = start->next;
            }
            else {
                prev = prev->next;
            }
            start = start->next;
        }
        if (prev->val == val && prev->next == nullptr) {
            head = nullptr;
        }
        return head;
    }
};
