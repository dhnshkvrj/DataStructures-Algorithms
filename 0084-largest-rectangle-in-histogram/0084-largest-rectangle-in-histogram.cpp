class Solution {
public:
    // T.C.= O(5N), S.C.= O(2N)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();;
        vector<int> nse(n) ,pse(n);
        stack<int>st;

        //  Finding NSE         T.C.= O(2N)
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        st=stack<int>();            // clearing the stack

        // Finding PSE          T.C.= O(2N)
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){       // T.C.= O(N)
            int ht=heights[i];
            ans= max(ans, ht*(nse[i]-pse[i]-1) );
        }
        return ans;
    }
};