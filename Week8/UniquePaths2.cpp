class Solution {
    int paths[101][101];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0;i<n;i++){
            if(!obstacleGrid[0][i])     
            paths[0][i] = 1;
            else break;
        }
        for(int i=0;i<m;i++){
            if(!obstacleGrid[i][0]) 
            paths[i][0] = 1;
            else break;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!obstacleGrid[i][j])
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];

    }
};
