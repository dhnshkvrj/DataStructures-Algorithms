class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++)
            dp[i]=vector(i+1,0);
        dp[0]={triangle[0][0]};

        for(int row=1;row<n;row++){
            for(int col=0;col<=row;col++){
                int up=1e9,left=1e9;
                if(col<row)    
                    up=dp[row-1][col];
                if(col>0)
                    left=dp[row-1][col-1];
                dp[row][col]=min(up,left)+triangle[row][col];
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
            mini=min(mini,dp[n-1][i]);
        return mini;
    }
};