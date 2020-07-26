class Solution {
private:
    vector<vector<int>> res;
    void dfs(int n, int k, int index, vector<int>& s) {
        if (s.size() == k) {
            res.push_back(s);
            return;
        }

        for (int i = index; i <= n; ++i) {
            s.push_back(i);
            dfs(n, k, i + 1, s);
            s.pop_back();
            
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        if (n == 0 || k == 0) {
            return res;
        }
        vector<int> s;
        dfs(n, k, 1, s);
        return res;
    }
};