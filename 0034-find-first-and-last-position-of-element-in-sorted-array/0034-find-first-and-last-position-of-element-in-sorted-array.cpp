class Solution {
public:
    // Method 2: 
    // By finding lower bound and upper bound
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;

        int lb=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                lb=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }

        low=0, high=n-1;
        int ub=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                ub=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        if(lb==n || nums[lb]!=target)  return {-1,-1};
        return {lb,ub-1};
    }
};