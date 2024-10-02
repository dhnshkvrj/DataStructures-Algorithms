class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];

        if(nums[0]!=nums[1])    return nums[0];
        if(nums[n-1]!=nums[n-2])  return nums[n-1];

        int low=1, high=n-2;            // We have trimmed the space to avoid extra check
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];

            
            // If both mid and mid+1 have same elements and
            // mid is even && mid-1 is odd
            // Similarly mid and mid-1 have same elements
            // mid is odd and mid-1 is even
            // Then the single element is on the right side of mid
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
            }
            else        // mid is odd and mid-1 is even, single element is on left side
                high=mid-1; 
        }
        return -1;
    }
};