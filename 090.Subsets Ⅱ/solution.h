class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& nums, int index, vector<int>& s) {
        res.push_back(s);

        for (int i = index; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            s.push_back(nums[i]);
            used[i] = true;
            dfs(nums, i + 1, s);
            s.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        used = vector<bool>(nums.size(), false);
        dfs(nums, 0, vec);
        return res;
    }
};