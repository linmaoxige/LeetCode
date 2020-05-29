class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curHead = new ListNode(0);
        curHead->next = head;

        ListNode* cur = curHead;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else {
                cur = cur->next;
            }
        }
        return curHead->next;
    }
};