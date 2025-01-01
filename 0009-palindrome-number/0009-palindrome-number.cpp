class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        long long y=0,n=x;
        while(n){
            int rem=n%10;
            n=n/10;
            y=y*10 + rem;
        }
        return x==y;
    }
};