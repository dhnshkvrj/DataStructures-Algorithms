class Solution {
public:
    bool check(int day, vector<int>& bloomDay,  int m, int k){
        int n=bloomDay.size();
        int cnt=0, num=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                num+=cnt/k;
                cnt=0;
            }
                
        }
        num+=cnt/k;
        return  num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n)   return -1;

        int mini=INT_MAX, maxi=INT_MIN;
        for(auto i:bloomDay){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }

        int low=mini, high=maxi, ans=maxi;

        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};