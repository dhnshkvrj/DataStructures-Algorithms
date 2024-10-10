class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> curr(n,0);
        vector<int> prev=matrix[0];

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int up=prev[col];
                int left=INT_MAX, right=INT_MAX;
                if(col>0)       left=prev[col-1];
                if(col<n-1)     right=prev[col+1];
                curr[col]=min(up,min(left,right))+matrix[row][col];
            }
            prev=curr;
        }

        int mini=INT_MAX;
        for(int i:prev)
            mini=min(mini,i);
        return mini;
    }
};