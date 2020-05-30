class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* r;
        dummyHead->next = NULL;
        while (head) {
            r = head->next;
            head->next = dummyHead->next;
            dummyHead->next = head;
            head = r;
        }
        return dummyHead->next;
    }
};