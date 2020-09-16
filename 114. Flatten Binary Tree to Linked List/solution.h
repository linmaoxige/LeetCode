class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->left != NULL) {
                auto next = cur->left;
                auto pre = next;
                while (pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->left = NULL;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};