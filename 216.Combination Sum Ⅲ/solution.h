class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(int k, int n, int index, vector<int>& s) {
        if (s.size() == k && n == 0) {
            res.push_back(s);
            return;
        }

        for (int i = index; i <= 9; ++i) {
            if (s.size() == k || n < i || used[i]) {
                continue;
            }
            s.push_back(i);
            used[i] = true;
            dfs(k, n - i, i + 1, s);
            s.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n == 0) {
            return res;
        }
        used = vector<bool>(10, false);
        vector<int> vec;
        dfs(k, n, 1, vec);
        return res;
    }
};