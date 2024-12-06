class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int j=0, cnt=0, sum=0;
        
        for(int i=1; i<=n; i++){
            while(j>0 && j<banned.size() && banned[j-1]==banned[j])
                j++;
            if(j<banned.size() && banned[j]==i){
                j++;
                continue;
            }
            
            if(sum+i<=maxSum){
                sum+=i;
                cnt++;
            }
            else
                break;
        }

        return cnt;
    }
};