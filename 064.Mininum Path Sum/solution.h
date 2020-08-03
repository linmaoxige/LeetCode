class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j > 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                if (j == 0 && i > 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if (i > 0 && j > 0) {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }
        return grid[row - 1][col - 1];
    }
};