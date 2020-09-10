/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int num = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != NULL) {
            convertBST(root->right);
            root->val += num;
            num = root->val;
            convertBST(root->left);
            return root;
        }
        return NULL;
    }
};