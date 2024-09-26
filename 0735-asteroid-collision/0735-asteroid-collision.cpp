class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto i:asteroids){
            if(i>0)     st.push(i);     // Initially stack stores only positive elements
            else{                       // If we encounter a negative element    
                while(!st.empty() && st.top()>0 && st.top()<abs(i))        
                    st.pop();           // If the neg ele is > st top, it destroys st top
                if(!st.empty() && st.top()==abs(i))            
                    st.pop();           // If both asteroids are of same size
                else if(st.empty() || st.top()<0)             // Storing negative elements 
                    st.push(i);
            }
        }
        // -2 -3 5 6    is not a problem bcoz -2 & -3 go left 5 & 6 go right => don't collide
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};