class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;
    void dfs(vector<int>& nums, int index, vector<int>& s) {
        if (nums.size() == index) {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {

            //当前nums[i]与nums[i-1]相同，如果nums[i-1]没有被访问过，则会重复，从这剪枝
            if (visited[i] || (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            s.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, index + 1, s);
            s.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        visited = vector<bool>(nums.size(), false);
        vector<int> s;
        dfs(nums, 0, s);
        return res;
    }
};