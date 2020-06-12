class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            TreeNode* p = q.front().first;
            int mindepth = q.front().second;
            q.pop();
            if (!p->left && !p->right) {
                return mindepth;
            }

            if (p->left) q.push(make_pair(p->left, mindepth + 1));
            if (p->right) q.push(make_pair(p->right, mindepth + 1));
        }
        return 0;
    }
};