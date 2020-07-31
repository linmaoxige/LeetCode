class Solution {
private:
    int m, n;
    int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
    vector<vector<bool>>visited;
    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && board[newx][newy] == 'O') {
                dfs(board, newx, newy);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) { //左边界
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) { //又边界
                dfs(board, i, n - 1);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) { //上边界
                dfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) { //下边界
                dfs(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n ; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};