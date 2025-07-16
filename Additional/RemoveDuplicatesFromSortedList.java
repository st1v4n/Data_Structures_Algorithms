/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Leetcode 83
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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)return null;
        ListNode result = head;
        ListNode previous = head;
        head = head.next;
        while(head != null){
            if(previous.val != head.val){
                previous.next = head;
                previous = head;
            }
            else{
                previous.next = null;
            }
            head = head.next;
        }
        return result;
    }
}
