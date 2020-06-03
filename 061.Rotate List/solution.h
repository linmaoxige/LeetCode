class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* r;
        int length = 0;
        ListNode* q = head;
        while (q) {
            length++;
            q = q->next;
        }
        k = k % length;

        while (k--) {
            ListNode* pre = dummyHead;
            ListNode* p = dummyHead->next;
            if (p->next) {
                while (p != NULL && p->next != NULL) {
                    pre = p;
                    p = pre->next;
                }
                r = p;
                r->next = dummyHead->next;
                dummyHead->next = r;
                pre->next = NULL;
            }
            else {
                r = p;
                r->next = dummyHead->next;
                dummyHead->next = r;
                pre = r;
                pre->next = NULL;
            }
        }
        return dummyHead->next;
    }
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        int length = 1;
        ListNode* p = head;
        while (p && p->next) {
            length++;
            p = p->next;
        }
        k = k % length;
        if (k == 0) return dummyHead->next;
        int n = length - k;
        ListNode* pre = dummyHead;
        ListNode* cur = pre->next;
        while (n--) {
            pre = cur;
            cur = pre->next;
        }
        p->next = dummyHead->next;
        dummyHead->next = cur;
        pre->next = NULL;
        return dummyHead->next;
    }
};