class Solution {
public:
    // Code from the other qn
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), maxi=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int eleInd=st.top();
                st.pop();
                int nse=i;
                int pse= st.empty() ? -1 : st.top();
                maxi=max(maxi, heights[eleInd]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse=n;
            int eleInd=st.top();
            st.pop();
            int pse=st.empty() ? -1 : st.top();
            maxi=max(maxi, heights[eleInd]*(nse-pse-1));
        }
        
        return maxi;
    }
    
    // This qn 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0')   sum=0;    
                prefix[i][j]=sum;
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,largestRectangleArea(prefix[i]));
        }
        return maxi;
    }
};