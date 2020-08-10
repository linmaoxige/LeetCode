class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        if (sl == 0 && tl == 0) return true;
        if (sl > tl) return false;
        for (int i = 0, j = 0; j < tl;) {
            if (s[i] == t[j]) {
                sl--;
                i++;
                j++;
            }
            else {
                j++;
            }
            if (sl == 0) return true;
        }
        return false;
    }
};