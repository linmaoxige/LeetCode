class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* nummyHead = new ListNode(0);
        ListNode* p = nummyHead;
        ListNode* r = nummyHead;
        ListNode* b;
        int count = 1;
        while (count<m) {
            r->next = head;
            r = head;
            head = head->next;
            count++;
        }
        r->next = NULL;
        while (count >= m && count <= n) {
            b = head->next;
            head->next = r->next;
            r->next = head;
            head = b;
            count++;
        }
        while (n--) {
            nummyHead = nummyHead->next;
        }
        if (head) {
            nummyHead->next = head;
        }
        return p->next;
    }
};