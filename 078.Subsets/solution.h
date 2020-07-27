class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int index, vector<int>& s) {
        res.push_back(s);

        for (int i = index; i < nums.size(); ++i) {
            s.push_back(nums[i]);
            dfs(nums, i + 1, s);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        dfs(nums, 0, vec);
        return res;
    }
};