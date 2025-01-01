class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int i=len-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        int j=i;
        while(i>=0 && s[i]!=' '){
            i--;
        }
        return j-i;
    }
};