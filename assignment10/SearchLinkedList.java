class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Solution {
    public String searchList(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return "Yes";
        }

        ListNode p2 = list2;

        while (p2 != null) {
            ListNode p1 = list1;
            ListNode current = p2;

            while (p1 != null && current != null && p1.val == current.val) {
                p1 = p1.next;
                current = current.next;
            }

            if (p1 == null) {
                return "Yes";
            }

            p2 = p2.next;
        }

        return "No";
    }
}
