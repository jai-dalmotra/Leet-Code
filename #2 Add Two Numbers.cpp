class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); // Fix: Use ListNode
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1 != NULL) {
                sum += temp1->val;  // Fix: Use val instead of data
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->val;  // Fix: Use val instead of data
                temp2 = temp2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode; // Fix: Link newNode to result list
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry); // Fix: Handle last carry
        }

        return dummyHead->next; // Skip dummy node
    }
};
