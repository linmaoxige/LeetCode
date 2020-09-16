class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> vec1(len, 1);
        vector<int> vec2(len, 1);
        vector<int> vec3(len, 1);
        for (int i = 1; i < len; i++) {
            if (i == 1) {
                vec1[i] = nums[0];
                vec2[len - i - 1] = nums[len - 1];
            }
            else {
                vec1[i] = vec1[i - 1] * nums[i - 1];
                vec2[len - i - 1] = vec2[len - i] * nums[len - i];
            }
        }
        for (int j = 0; j < len; j++) {
            vec3[j] = vec1[j] * vec2[j];
        }
        return vec3;
    }
};