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

        while(low<=high){
            int mid=(low+high)/2;

            if(findSum(mid,nums)<=threshold)    high=mid-1;
            else                                low=mid+1;
        }
        return low;
        // For high=div=maxi, it is always possible 
        // for if so when it ends (low>high) high will be in not possible case
        // and low will be the possible case => answer
        // (opposite polarity)
    }
};