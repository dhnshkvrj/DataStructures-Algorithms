class Solution {
public:
    vector<int> f(vector<int>& a)
    {
        int n=a.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a[i])
                st.pop();
            if(st.empty())  nge[i]=-1;
            else nge[i]=st.top();
            st.push(a[i]);
        }
        return nge;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge=f(nums2);
        vector<int> ans;
        for(auto i:nums1)
        {
            int pos=find(nums2.begin(),nums2.end(),i)-nums2.begin();
            ans.push_back(nge[pos]);
        }
        return ans;
    }
};