class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=nums[0];
        int low=0, high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;
            mini=min(mini,nums[mid]);

            // Left is sorted
            if(nums[low]<=nums[mid]){
                mini=min(nums[low],mini);
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return mini;
    }
};