class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
    bool dfs(TreeNode* root, const int& sum, int now) {
        if (root == nullptr) return false;
        now += root->val;
        if (root->left == nullptr && root->right == nullptr && now == sum) return true;
        if (dfs(root->left, sum, now) || dfs(root->right, sum, now)) return true;
        return false;
    }
};