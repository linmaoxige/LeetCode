class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& s,int index) {
        if (target == 0) {
            res.push_back(s);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                return;
            }
            s.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], s, i);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        vector<int> q;
        dfs(candidates, target,q,0);
        return res;
    }
};