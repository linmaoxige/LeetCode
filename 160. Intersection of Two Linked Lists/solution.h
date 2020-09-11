class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return NULL;
        }
        ListNode* pa = headA, * pb = headB;
        while (pa != pb) {
            pa = pa == NULL ? headB : pa->next;
            pb = pb == NULL ? headA : pb->next;
        }
        return pa;
    }
};