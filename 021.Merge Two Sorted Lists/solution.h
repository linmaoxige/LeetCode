class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                dummyHead->next = l1;
                l1 = l1->next;
                dummyHead = dummyHead->next;
            }
            else {
                dummyHead->next = l2;
                l2 = l2->next;
                dummyHead = dummyHead->next;
            }
        }
        dummyHead->next = l1 ? l1 : l2;
        return p->next;
    }
};