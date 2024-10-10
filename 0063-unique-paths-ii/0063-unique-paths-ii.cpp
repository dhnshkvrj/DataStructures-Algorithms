class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)  return 0;
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0)
                    dp[0][0]=1;
                else if(obstacleGrid[row][col]==1)
                    dp[row][col]=0;
                else{
                    int left=0,up=0;
                    if(col>0)   left=dp[row][col-1];
                    if(row>0)   up=dp[row-1][col];
                    dp[row][col]=left+up;
                }
            }
        }

        return dp[n-1][m-1];
    }
};