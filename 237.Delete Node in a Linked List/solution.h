class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node->next;
        node->val = p->val;
        ListNode* delNode = p;
        node->next = p->next;
        delete delNode;
    }
};