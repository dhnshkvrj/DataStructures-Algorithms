class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                cnt++;
                nums[j]=nums[i];
                j++;
            }
        }
        return cnt;
    }
};