class Solution {
private:
    vector<int> memo;
    int breakInteger(int n) {
        if (n == 1) {
            return 1;
        }
        if (memo[n]) {
            return memo[n];
        }
        int res = -1;
        for (int i = 1; i < n; i++) {
            res = max(res, max(i * (n - i), i * breakInteger(n - i)));
        }
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {
        memo = vector<int>(n + 1, 0);
        return breakInteger(n);
    }
};