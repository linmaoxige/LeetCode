class Solution {
public:
    
    void dfs(TreeNode* root, int sum, vector<int> v, vector<vector<int>> &res) {
        if (root == nullptr) return;
        v.push_back(root->val);
        if (root->left== nullptr && root->right == nullptr) {
            if(sum == root->val) res.push_back(v);
            return;
        }
        dfs(root->left, sum - root->val, v,res);
        dfs(root->right, sum - root->val, v,res);

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        dfs(root, sum, {},res);
        return res;
    }
};