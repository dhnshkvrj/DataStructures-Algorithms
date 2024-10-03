class Solution {
public:
    long long findSum(int div, vector<int>& nums){
        long long sum=0;
        for(int i:nums)
            sum+=ceil( i*1.0/div*1.0 );
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=0;
        for(int i:nums)
            maxi=max(maxi,i);
        
        int low=1, high=maxi;
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(findSum(mid,nums)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};