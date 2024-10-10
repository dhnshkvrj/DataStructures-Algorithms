class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int ind=2;ind<=n;ind++){
            int left=dp[ind-2];
            int right=dp[ind-1];
            dp[ind]=left+right;
        }
        return dp[n];
    }
};