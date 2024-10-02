class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i:piles)
            maxi=max(maxi,i);
        
        int low=1, high=maxi,ans=-1;

        while(low<=high){
            int mid=(low+high)/2;
            long long hours=0;
            for(int i:piles)
                hours+=ceil((i*1.0)/(mid*1.0));
            
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};