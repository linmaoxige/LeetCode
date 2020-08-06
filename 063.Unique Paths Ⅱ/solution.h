class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        obstacleGrid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && obstacleGrid[0][j] == 0) {
                    obstacleGrid[0][j] = obstacleGrid[0][j - 1];
                }
                else if (i == 0 && obstacleGrid[0][j] == 1 && j > 0) {
                    obstacleGrid[0][j] = 0;
                }

                if (j == 0 && obstacleGrid[i][0] == 0) {
                    obstacleGrid[i][0] = obstacleGrid[i-1][0];
                }
                else if (j == 0 && obstacleGrid[i][0] == 1 && i > 0) {
                    obstacleGrid[i][0] = 0;
                }
                if (i > 0 && j > 0) {
                    if (obstacleGrid[i][j] == 1) {
                        obstacleGrid[i][j] = 0;
                    }
                    else {
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                    }
                    
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", obstacleGrid[i][j]);
            }
            printf("\n");
        }
        return obstacleGrid[m - 1][n - 1];
    }
};