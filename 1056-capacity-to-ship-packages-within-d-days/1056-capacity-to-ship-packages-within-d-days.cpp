class Solution {
public:
    bool check(int capacity, vector<int>& weights, int days){
        int d=0, currCapacity=0;;
        for(int i:weights){
            currCapacity+=i;
            if(currCapacity>capacity){
                d++;
                currCapacity=i;
            }
        }
        d+=ceil((double)currCapacity/(double)capacity);
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxi=INT_MIN;
        for(int i:weights){
            maxi=max(maxi,i);
            sum+=i;
        }

        int low=maxi, high=sum;

        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,weights,days))     high=mid-1;
            else                            low=mid+1;
        }
        return low;
    }
};