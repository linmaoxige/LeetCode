class Solution {
    int ans;
    int depth(TreeNode* rt) {
        if (rt == NULL) return 0;
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};