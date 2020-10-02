class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (1) {
            if (fast == NULL || fast->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};