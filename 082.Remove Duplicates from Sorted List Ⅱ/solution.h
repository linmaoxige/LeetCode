class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)return head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        while (head && head->next) {
            if (head->val != head->next->val) {
                pre = head;
                head = head->next;
            }
            else {
                while (!head->next && head->val == head->next->val) {
                    head = head->next;
                }
                pre->next = head->next;
                head = head->next;
            }
        }
        return dummyHead->next;
    }
};