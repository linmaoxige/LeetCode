class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum;
        if (root->left != NULL && !root->left->left && !root->right->right) sum += root->val;
        if (root->left) sumOfLeftLeaves(root->left);
        if (root->right) sumOfLeftLeaves(root->right);
        return sum;
    }
};