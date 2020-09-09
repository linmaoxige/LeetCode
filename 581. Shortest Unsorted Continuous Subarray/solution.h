class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin(), t.end());
        int m, n;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != t[i]) {
                m = i;
                break;
            }
            if (nums[i] == t[i] && i == nums.size() - 1) {
                return 0;
            }
        }
        for (int j = nums.size() - 1; j > 0; j--) {
            if (nums[j] != t[j]) {
                n = j;
                break;
            }
        }
        return n - m + 1;
    }
};