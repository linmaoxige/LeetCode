class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int previousIndex = st.top();
                ans[previousIndex] = i - previousIndex;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};