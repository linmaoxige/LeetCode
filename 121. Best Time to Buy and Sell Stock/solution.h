class Solution {
public:
    int min_v = 0;
    int max_v = 0;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        min_v = prices[0];
        for (int i = 0; i < len; i++) {
            min_v = min(min_v, prices[i]);
            max_v = max(max_v, prices[i] - min_v);
        }
        return max_v;
    }
};