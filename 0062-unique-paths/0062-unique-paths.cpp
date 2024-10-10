class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>curr(n,0),prev(n,0);
        
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 &&  col==0)   
                    curr[0]=1;
                else{
                    int left=0, up=0;
                    if(col>0)   left=curr[col-1];
                    if(row>0)   up=prev[col];
                    curr[col]=left+up;
                }
            }
            prev=curr;
        }

        return prev[n-1];
    }
};