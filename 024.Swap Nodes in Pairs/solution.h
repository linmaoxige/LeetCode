class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while (p->next && p->next->next)
        {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;

            p->next = node2;
            node2->next = node1;
            node1->next = next;

            p = node1;
        }
        return dummyHead->next;
    }
};