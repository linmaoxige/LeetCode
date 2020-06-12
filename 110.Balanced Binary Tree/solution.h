class Solution {
public:
    int flag = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (abs(l - r) > 1) flag = 1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        if (flag) return false;
        return true;
    }
};