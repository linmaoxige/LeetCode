class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (depth == res.size()) res.push_back(vector<int>());
            res[depth].push_back(node->val);
            

            if (node->left) q.push(make_pair(node->left, depth + 1));
            if (node->right) q.push(make_pair(node->right, depth + 1));
            
        }
        return res;
    }
};