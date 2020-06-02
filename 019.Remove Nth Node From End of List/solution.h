class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = pre->next;
        ListNode* p = dummyHead->next;
        while (n--) {
            p = p->next;
        }
        while (cur) {
            if (p == NULL) {
                ListNode* delNode = cur;
                pre->next = cur->next;
                delete delNode;
                break;
            }
            else {
                pre = cur;
                cur = pre->next;
                p = p->next;
            }
        }
        return dummyHead->next;
    }
};