class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            if (i == 2) nums[i] += nums[i - 2];
            else {
                nums[i] += max(nums[i - 2], nums[i - 3]);
            }
            
        }
        return max(nums[n - 1], nums[n - 2]);
    }
};