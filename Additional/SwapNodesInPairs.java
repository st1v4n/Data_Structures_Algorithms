/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Leetcode 24
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null)return head;
        ListNode nxt = head.next;
        ListNode prev = head;
        boolean isSwapped = false;
        while(nxt != null){
            if(nxt.next != null){
                ListNode current = nxt.next;
                if(nxt.next.next != null){
                    prev.next = nxt.next.next;
                    nxt.next = prev;
                }
                else{
                    prev.next = current;
                    nxt.next = prev;
                }
                if(!isSwapped){
                    head = nxt;
                    isSwapped = true;
                }
                prev = current;
                nxt = current.next;
            }
            else{
                prev.next = null;
                nxt.next = prev;
                if(!isSwapped){
                    head = nxt;
                }
                break;
            }
        }
        return head;
    }
}
