class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>>q;
        vector<bool>visited(n + 1, false);
        visited[n] = true;
        q.push(make_pair(n, 0));
        
        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1; num - i * i >= 0; i++) {
                if (num - i * i == 0) {
                    return step;
                }

                if (!visited[num - i * i]) {
                    q.push(make_pair(num - i * i, step + 1));
                    visited[num - i * i] = true;
                }
                
            }
        }
        return 0;
    }
};