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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy=new ListNode(-1);
        ListNode crr=dummy;

        while(l1!=null&&l2!=null)
        {
            if(l1.val<=l2.val){
                crr.next=l1;
                l1=l1.next;
            }
            else{
                crr.next=l2;
                l2=l2.next;
            }
            crr=crr.next;    
        }

        if(l1!=null){
            crr.next=l1;
        }
        else if(l2!=null)
        {
            crr.next=l2;
        }

    return dummy.next;    

    }
}
