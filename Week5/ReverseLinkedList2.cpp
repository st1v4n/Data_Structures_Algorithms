/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)return head;
        ListNode* start = head;
        ListNode* l = head;
        ListNode* prev = nullptr;
        int curr = 1;
        while (head) {
            if (curr == left) {
                l = head;
                ListNode* copyPrev = prev;
                for (int i = left;i <= right;i++) {
                    ListNode* nxt = head->next;
                    head->next = prev;
                    prev = head;
                    head = nxt;
                }
                l->next = head;
                if (copyPrev) {
                    copyPrev->next = prev;
                }
                if (left == 1) {
                    start = prev;
                }
                break;
            }

            curr++;
            prev = head;
            head = head->next;
        }
        return start;
    }
};