class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& candidates, int target, int index,vector<int>& s) {
        if (target == 0) {
            res.push_back(s);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if ((i > 0 && !used[i - 1] && candidates[i] == candidates[i - 1]) || target-candidates[i] < 0) {
                continue;
            }
            s.push_back(candidates[i]);
            used[i] = true;
            dfs(candidates, target - candidates[i], i + 1, s);
            s.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0) {
            return res;
        }
        used = vector<bool>(candidates.size(), false);
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        return res;
    }
};