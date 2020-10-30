class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector < vector<string>> res;
        unordered_map<string, vector<string>> um;
        string str;
        for (auto& s : strs) {
            str = s;
            sort(str.begin(), str.end());
            um[str].push_back(s);
        }
        for (auto& c : um) {
            res.push_back(c.second);
        }
        return res;
    }
};