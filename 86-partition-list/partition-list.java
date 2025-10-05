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
    public ListNode partition(ListNode head, int x) {
        ListNode less = new ListNode(-1), rest = new ListNode(-1);
        ListNode cur = head, curLess = less, curRest = rest;
        while(cur != null) {
            if(cur.val < x) {
                curLess.next = new ListNode(cur.val);
                curLess = curLess.next;
            }
            else {
                curRest.next = new ListNode(cur.val);
                curRest = curRest.next;
            }
            cur = cur.next;
        }
        curLess.next = rest.next;
        return less.next;
    }
}