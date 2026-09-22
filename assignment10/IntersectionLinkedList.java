class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Solution {

    public ListNode intersection(ListNode head1, ListNode head2) {

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        ListNode p1 = head1;
        ListNode p2 = head2;

        while (p1 != null && p2 != null) {

            if (p1.val == p2.val) {
               tail.next = new ListNode(p1.val);
                tail = tail.next;

                p1 = p1.next;
                p2 = p2.next;
            }
            else if (p1.val < p2.val) {
                p1 = p1.next;
            }
            else {
                p2 = p2.next;
            }
        }

        return dummy.next;
    }
}
