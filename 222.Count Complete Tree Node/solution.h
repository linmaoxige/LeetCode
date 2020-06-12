class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};