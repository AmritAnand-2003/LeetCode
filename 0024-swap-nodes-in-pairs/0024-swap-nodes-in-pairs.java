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
        ListNode cur = head, start = new ListNode(-1, head);
        ListNode prev = start;
        while(cur != null && cur.next != null) {
            prev.next = cur.next;
            cur.next = cur.next.next;
            prev.next.next = cur;
            prev = cur;
            cur = cur.next;
        }
        return start.next;
    }
}