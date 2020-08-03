class Solution {
private:
    vector<int> memo;
    int climbWay(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memo[n] == -1) {
            memo[n] = climbWay(n - 1) + climbWay(n - 2);
        }
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo = vector<int>(n + 1, -1);
        return climbWay(n);
    }
};
