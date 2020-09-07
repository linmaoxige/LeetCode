class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 1));
        }
        for (int j = 0; j < numRows; j++) {
            for (int k = 1; k < j; k++) {
                ans[j][k] = ans[j - 1][k - 1] + ans[j - 1][k];
            }
        }
        return ans;
    }
};