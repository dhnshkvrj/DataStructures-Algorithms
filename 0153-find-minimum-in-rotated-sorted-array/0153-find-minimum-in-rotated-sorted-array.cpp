class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=nums[0];
        int low=0, high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            // Entire array is sorted
            if(nums[low]<=nums[high]){
                mini=min(mini,nums[low]);
                break;
            }

            // Left half is sorted
            if(nums[low]<=nums[mid]){
                mini=min(nums[low],mini);
                low=mid+1;
            }
            // Right half is sorted
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};