class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n=arr.size();
        vector<int> nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();

            if(st.empty())      nse[i]=n;
            else                nse[i]=st.top();
            
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr){
        int n=arr.size();
        vector<int> psee(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();

            if(st.empty())      psee[i]=-1;
            else                psee[i]=st.top();
            
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // We basically find the no of subarrays a particular element will be the smallest
        // and we multiply the element by the number of subarrays and add to sum
        // to find the no of subarrays it will be the smallest ele
        // we find NSE(next smaller element) & PSEE(prev smaller or equal element)
        // Taking PSE insead of PSEE will have give wrong ans for some cases ex [1,1]
        // right = nse-i
        // left  = i-psee
        // m= right*left 
        // initialise NSE array with N, and PSEE array with -1 

        int n=arr.size(), mod=1e9+7;;
        vector<int> nse=findNSE(arr);
        vector<int> psee=findPSEE(arr);
        
        long long ans=0;
        for(int i=0;i<n;i++){
            long long right=nse[i]-i;
            long long left=i-psee[i];
            ans=(ans + (arr[i]*right*left*1LL)%mod *1LL)%mod;
        }
        return ans;   
    }
};