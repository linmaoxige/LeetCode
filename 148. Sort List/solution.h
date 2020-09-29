class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        return (head == NULL) ? NULL : mergeSort(head);
    }

private:
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeSort(ListNode* head)
    {
        if (!head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(mid);
        return mergeTwoLists(l1, l2);
    }
};