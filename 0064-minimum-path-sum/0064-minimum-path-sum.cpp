class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> prev(m,0), curr(m,0);

        for(int row=0; row<n; row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0)    curr[0]=grid[0][0];
                else{
                    int left=1e9, up=1e9;
                    if(row>0)   up=prev[col];
                    if(col>0)   left=curr[col-1];
                    curr[col]=min(left,up)+grid[row][col];
                }
            }
            prev=curr;
        }

        return prev[m-1];
    }
};