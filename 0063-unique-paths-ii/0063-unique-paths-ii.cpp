class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)  return 0;
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<int>prev(m,0), curr(m,0);

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0)
                    curr[0]=1;
                else if(obstacleGrid[row][col]==1)
                    curr[col]=0;
                else{
                    int left=0,up=0;
                    if(col>0)   left=curr[col-1];
                    if(row>0)   up=prev[col];
                    curr[col]=left+up;
                }
            }
            prev=curr;
        }

        return prev[m-1];
    }
};