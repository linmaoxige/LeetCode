class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for (int j = ptr; j < nums.size(); j++) {
            if (nums[j] == 1) {
                swap(nums[j], nums[ptr]);
                ptr++;
            }
        }
    }
};