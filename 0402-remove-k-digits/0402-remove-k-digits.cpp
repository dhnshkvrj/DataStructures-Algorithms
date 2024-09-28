class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(int i=0;i<num.length();i++){        
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();           
                k--;                // If element that is at top of stack is grater than the 
            }                       // element at the index i, we remove stack element
            st.push(num[i]);        // as we want smaller elements in the answer
        }

        while(k>0){                 // if we cant remove elements i.e. all are in ascending 
            st.pop();               // order => we remove the last few elements (greater ones)
            k--;
        }

        if(st.empty())   return "0";

        string res="";              // Put from stack to string
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        int i=0;                    
        reverse(res.begin(),res.end());     // revrese string

        while(res[i]=='0')                  // Removing 0's at the front
            i++;
        res=res.substr(i,res.size()-i);
        
        if(res.size()==0)   return "0";
        return res;
    }
};