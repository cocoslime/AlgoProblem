/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode mid = head;
        ListNode findEnd = head;

        if (head.next == null)
            return head;

        while (true){
            findEnd = findEnd.next;
            mid = mid.next;
            if (findEnd.next == null){
                return mid;
            }

            findEnd = findEnd.next;
            if (findEnd.next == null){
                return mid;
            }
        }
    }
}

public class prob876 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, null))));
        solution.middleNode(head);
    }
}
