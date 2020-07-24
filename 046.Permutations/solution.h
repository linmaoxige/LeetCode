class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void per(vector<int>& nums, int index, vector<int>& s) {
        if (nums.size() == index) {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                s.push_back(nums[i]);
                used[i] = true;
                per(nums, index + 1, s);
                s.pop_back();
                used[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        per(nums, 0, p);
        return res;
    }
};