class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefixMax(n,0), suffixMax(n,0);
        prefixMax[0]=height[0];
        suffixMax[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);

            int ind=n-1-i;
            suffixMax[ind]=max(suffixMax[ind+1],height[ind]);
        }

        int qty=0;
        for(int i=0;i<n;i++)
            if(height[i]<prefixMax[i] && height[i]<suffixMax[i])
                qty+=min(prefixMax[i],suffixMax[i])-height[i];

        return qty;
    }
};